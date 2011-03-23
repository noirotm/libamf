add_library(gtest STATIC gtest/gtest.cpp gtest/gtest.h)

include_directories(${CMAKE_SOURCE_DIR}/tests)

macro(ADD_GTEST test)
  add_executable(${test} ${test}.cpp ${MINI_CPP_UNIT_FILES} ${ARGN})
  add_test(${test} ${test})
  target_link_libraries(${test} amf gtest)
endmacro(ADD_GTEST)

include_directories(${CMAKE_SOURCE_DIR}/include)

ADD_GTEST(test_data)