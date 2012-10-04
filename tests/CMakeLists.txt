message("Test =====================================================")

enable_testing()
add_test(InputTest "lua" ${CMAKE_CURRENT_SOURCE_DIR}/lua/InputTest.lua ${CMAKE_SOURCE_DIR}/assets/scripts/?.lua)
