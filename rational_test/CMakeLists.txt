# CMakeList.txt : CMake project for rational, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable(rational_test "rational_test.cpp")

target_link_libraries(rational_test "gtest_main" "rational")

set_property(TARGET rational PROPERTY CXX_STANDARD 20)

# GoogleTest library
# See: https://github.com/google/googletest/blob/master/googletest/README.md

# Download library source code
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()