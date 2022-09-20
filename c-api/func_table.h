#pragma once
#include <cstdint>
#include "core.h"
#include "altv.h"
#include "client.h"
#include "config.h"
#include "connection_info.h"
#include "core.h"
#include "event.h"
#include "localstorage.h"
#include "map_data.h"
#include "mvalue.h"
#include "resource.h"
#include "weaponData.h"
#include "entities/audio.h"
#include "entities/baseObject.h"
#include "entities/blip.h"
#include "entities/checkpoint.h"
#include "entities/colshape.h"
#include "entities/entity.h"
#include "entities/http_client.h"
#include "entities/object.h"
#include "entities/player.h"
#include "entities/rml_document.h"
#include "entities/rml_element.h"
#include "entities/vehicle.h"
#include "entities/voice_channel.h"
#include "entities/websocket_client.h"
#include "entities/webview.h"
#include "entities/worldObject.h"
#include <type_traits>

typedef struct {
    uint32_t size;
    uint64_t* hashes;
    void** pointers; 
} capi_func_table_t;

const capi_func_table_t* get_func_table();