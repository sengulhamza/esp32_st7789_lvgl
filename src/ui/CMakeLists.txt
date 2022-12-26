set(sources
    src/ui.c
    src/ui_helpers.c
    src/ui_font_Number.c
    src/ui_events.c
)

idf_component_register(
    SRCS ${sources}
    INCLUDE_DIRS . inc inc/ui
    REQUIRES driver
             esp_lcd
             lvgl
)

if (GCOV_BUILD)
MESSAGE(STATUS "Gcov build enabled for core component")
set_source_files_properties(
    ${sources}
    PROPERTIES COMPILE_FLAGS
    --coverage
)
endif()
