add_library(rational STATIC "rational.cpp" "rational.hpp" )

target_include_directories(rational PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
