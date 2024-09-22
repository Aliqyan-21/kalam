cmake_minimum_required(VERSION 3.10)
project(kalam VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include_directories(include)
add_library(kalam src/image.cpp src/load.cpp src/save.cpp src/kalam.cpp)

set_target_properties(kalam PROPERTIES 
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

install(TARGETS kalam
    EXPORT kalamConfig
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT kalamConfig DESTINATION lib/cmake/kalam)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/kalamConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/kalamConfigVersion.cmake"
    DESTINATION lib/cmake/kalam
)

set_target_properties(kalam PROPERTIES
    INSTALL_RPATH "$ORIGIN/../lib"  
    BUILD_WITH_INSTALL_RPATH ON     
    SKIP_BUILD_RPATH FALSE
    SKIP_INSTALL_RPATH FALSE
)

install(CODE "execute_process(COMMAND /sbin/ldconfig)")

install(CODE "
    message(STATUS \"Updating shared library cache...\")
    execute_process(COMMAND bash -c \"echo '/usr/local/lib' > /etc/ld.so.conf.d/kalam.conf\")
    execute_process(COMMAND ldconfig)
")
