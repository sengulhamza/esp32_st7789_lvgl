set(sources
    src/app_mngr.c
    src/display_panel_mngr.c
)

idf_component_register(
    SRCS ${sources}
    INCLUDE_DIRS . inc inc/app
    REQUIRES freertos
            esp_system
            esp_lcd
            lwip
            efuse
            esp_netif
            esp_event
            nvs_flash
            app_update
            core
            ui
            json
)

target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_20)

if (GCOV_BUILD)
MESSAGE(STATUS "Gcov build enabled for app component")
set_source_files_properties(
    ${sources}
    PROPERTIES COMPILE_FLAGS
    --coverage
)
endif()
