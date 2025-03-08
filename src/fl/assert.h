#pragma once



#include "fl/warn.h"
#include "fl/strstream.h"

#ifndef DEBUG
#define FASTLED_ASSERT(x, MSG) FASTLED_WARN_IF(!(x), MSG)
#else

#ifdef ESP32
#include "esp_log.h"
#include "esp_check.h"
#define FASTLED_ASSERT(x, MSG)                                                \
    {                                                                         \
        if (!(x)) {                                                           \
            ESP_ERROR_CHECK(ESP_FAIL);                                        \
        }                                                                     \
    }
#else
#define FASTLED_ASSERT(x, MSG) FASTLED_WARN_IF(!(x), MSG)
#endif
#endif

// ESP_LOGE("#### FastLED", "%s", (fl::StrStream() << MSG).c_str());
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// NOTE DELETED LINE BEFORE ESP_ERROR_CHECK because I cant correct the error: 
// .pio/libdeps/debug/FastLED/src/fl/assert.h:19:13: error: there are no arguments to 'ESP_LOGE' that depend on a template parameter, so a declaration of 'ESP_LOGE' must be available [-fpermissive]
