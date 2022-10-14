#pragma once

struct ClrConfigNodeData {
    uint8_t type = (uint8_t) Config::Value::Type::NONE;
    char* strValue = nullptr;
    uint8_t boolValue = 0;
    int64_t numValue = 0;
    int32_t elements = 0;
    char** keys = nullptr;
    ClrConfigNodeData** values = nullptr;

    ClrConfigNodeData(Config::Value::ValuePtr node) {
        auto nodeType = node->GetType();
        type = (uint8_t) nodeType;
        switch (nodeType) {
            case Config::Value::Type::STRING: {
                const auto str = node->As<std::string>();

                strValue = new char[str.length() + 1];
                std::copy(str.begin(), str.end(), strValue);
                strValue[str.length()] = '\0';

                break;
            }
            case Config::Value::Type::BOOL: {
                const auto nodeBool = node->As<bool>();

                boolValue = nodeBool;
                break;
            }
            case Config::Value::Type::NUMBER: {
                const auto nodeNumber = node->As<double>();

                numValue = nodeNumber;
                break;
            }
            case Config::Value::Type::LIST: {
                const auto list = node->As<std::vector<Config::Value::ValuePtr>>();
                elements = list.size();
                values = new ClrConfigNodeData*[elements];
                for (int i = 0; i < elements; i++) {
                    values[i] = new ClrConfigNodeData(list[i]);
                }
                break;
            }
            
            case Config::Value::Type::DICT: {
                const auto dict = node->As<std::map<std::string, Config::Value::ValuePtr>>();
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
            
            case Config::Value::Type::NONE:
            default:
                break;
        }
    }

    ~ClrConfigNodeData() {
        delete[] strValue;
        for (int i = 0; i < elements; i++) {
            if (type == (uint8_t) Config::Value::Type::DICT)
                delete[] keys[i];
            delete values[i];
        }
        delete[] keys;
        delete[] values;
    }
};