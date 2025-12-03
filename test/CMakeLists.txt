add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include)

add_executable(runTests runAllTests.cpp TodolistTest.cpp ActivityTest.cpp)
target_link_libraries(runTests gtest gtest_main core)