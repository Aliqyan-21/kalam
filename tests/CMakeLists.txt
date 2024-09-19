add_executable(test_image test_image.cpp)
target_link_libraries(test_image PRIVATE kalam)

add_executable(test_load test_load.cpp)
target_link_libraries(test_load PRIVATE kalam)

add_executable(test_save test_save.cpp)
target_link_libraries(test_save PRIVATE kalam)

add_executable(test_utils test_utils.cpp)
target_link_libraries(test_utils PRIVATE kalam)

add_test(NAME TestImage COMMAND test_image)
add_test(NAME TestLoad COMMAND test_load)
add_test(NAME TestSave COMMAND test_save)
add_test(NAME TestUtils COMMAND test_utils)
