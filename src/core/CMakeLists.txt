set(sources

)

idf_component_register(
    SRCS ${sources}
    INCLUDE_DIRS . inc inc/core
    REQUIRES freertos
            spiffs
            common
            mbedtls
            esp_wifi
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
