set(sources
    src/st7789_panel_driver.c
)

idf_component_register(
    SRCS ${sources}
    INCLUDE_DIRS . inc inc/core
    REQUIRES freertos
            esp_timer
            esp_lcd
            driver
)

if (GCOV_BUILD)
MESSAGE(STATUS "Gcov build enabled for core component")
set_source_files_properties(
    ${sources}
    PROPERTIES COMPILE_FLAGS
    --coverage
)
endif()
