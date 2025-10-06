# CMakeList.txt : CMake project for rational, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (rational "rational.cpp" "rational.hpp")

target_link_libraries(rational "gtest_main")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET rational PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
