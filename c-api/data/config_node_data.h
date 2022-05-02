#pragma once

struct ClrConfigNodeData {
    uint8_t type = (uint8_t) alt::config::Node::Type::NONE;
    char* strValue = nullptr;
    int32_t elements = 0;
    char** keys = nullptr;
    ClrConfigNodeData** values = nullptr;

    ClrConfigNodeData(alt::config::Node node) {
        auto nodeType = node.GetType();
        type = (uint8_t) nodeType;
        switch (nodeType) {
            case alt::config::Node::Type::SCALAR: {
                const auto str = node.ToString();
                strValue = new char[str.length() + 1];
                std::copy(str.begin(), str.end(), strValue);
                strValue[str.length()] = '\0';
                break;
            }
            
            case alt::config::Node::Type::LIST: {
                const auto list = node.ToList();
                elements = list.size();
                values = new ClrConfigNodeData*[elements];
                for (int i = 0; i < elements; i++) {
                    values[i] = new ClrConfigNodeData(list[i]);
                }
                break;
            }
            
            case alt::config::Node::Type::DICT: {
                const auto dict = node.ToDict();
                elements = dict.size();
                keys = new char*[elements];
                values = new ClrConfigNodeData*[elements];
                int i = 0;
                for (auto& pair : dict) {
                    keys[i] = new char[pair.first.length() + 1];
                    std::copy(pair.first.begin(), pair.first.end(), keys[i]);
                    keys[i][pair.first.length()] = '\0';
                    values[i] = new ClrConfigNodeData(pair.second);
                    i++;
                }
                break;
            }
            
            case alt::config::Node::Type::NONE:
            default:
                break;
        }
    }

    ~ClrConfigNodeData() {
        delete[] strValue;
        for (int i = 0; i < elements; i++) {
            if (type == (uint8_t) alt::config::Node::Type::DICT)
                delete[] keys[i];
            delete values[i];
        }
        delete[] keys;
        delete[] values;
    }
};