aux_source_directory(${CMAKE_SOURCE_DIR}/src FILE_SRC)

set(FILE_TEST
    test_main.cc
    test_inv.cc
    )

add_executable(unit_tests
    ${FILE_TEST}
    ${FILE_SRC}
    )
 
target_link_libraries(unit_tests
    PRIVATE
    fmt-header-only)