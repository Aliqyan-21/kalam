cmake_minimum_required(VERSION 3.28.2)
project(kalam VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(
  kalam
  src/kalam.cpp
  src/image.cpp
  src/load.cpp
  src/save.cpp
  src/utils.cpp
)

target_include_directories(kalam PUBLIC include)

find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

target_link_libraries(kalam PRIVATE PNG::PNG JPEG::JPEG)

add_executable(example examples/example_usage.cpp)
target_link_libraries(example PRIVATE kalam)

enable_testing()
add_subdirectory(tests)
