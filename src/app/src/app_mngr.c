#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_ota_ops.h"
#include "cJSON.h"
#include "core_includes.h"
#include "app/app_config.h"
#include "app/app_types.h"
#include "app/display_panel_mngr.h"

static const char *TAG = "appmngr";

static void app_core_init(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

#ifdef DEBUG_BUILD
static void print_app_info(void)
{
    const esp_partition_t *running = esp_ota_get_running_partition();
    esp_app_desc_t app_desc;
    ESP_ERROR_CHECK(esp_ota_get_partition_description(running, &app_desc));

    ESP_LOGI(TAG, "%s %s has started from @%" PRIu32 "",
             app_desc.project_name,
             app_desc.version,
             running->address
            );
}

static void print_heap_usage(const char *msg)
{
    ESP_LOGW(TAG, "(%s):free_heap/min_heap size %" PRIu32 "/%" PRIu32 " Bytes",
             msg,
             esp_get_free_heap_size(),
             esp_get_minimum_free_heap_size());
}

#endif

esp_err_t app_start(void)
{
#ifdef DEBUG_BUILD
    esp_log_level_set("*", ESP_LOG_INFO);           // set all components to INFO level
#else
    esp_log_level_set("*", ESP_LOG_NONE);           // disable logs for all components
#endif

    app_core_init();

#ifdef DEBUG_BUILD
    print_app_info();
#endif

    esp_err_t status = ESP_OK;
    display_panel_mngr_init();
    ESP_LOGI(TAG, "first init done... status: %d", status);

#ifdef DEBUG_BUILD
    print_heap_usage("after first init");
#endif

    return ESP_OK;
}
