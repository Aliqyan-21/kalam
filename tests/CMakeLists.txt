add_executable(test_image test_image.cpp)
target_link_libraries(test_image PRIVATE kalam)

add_test(NAME TestImage COMMAND test_image)
