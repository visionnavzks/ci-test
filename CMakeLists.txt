cmake_minimum_required(VERSION 3.20)
project(ci-test VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)

add_executable(ci-test src/main.cpp)
target_link_libraries(ci-test PRIVATE fmt::fmt)

install(TARGETS ci-test RUNTIME DESTINATION bin)

# CPack packaging
set(CPACK_PACKAGE_NAME "ci-test")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ci-test - C++ project with vcpkg")
set(CPACK_PACKAGE_VENDOR "ci-test")

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

include(CPack)
