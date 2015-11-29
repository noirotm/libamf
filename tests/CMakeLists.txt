# unit tests
if (CHECK_FOUND)
  include_directories(${CHECK_INCLUDE_DIRS})
  include_directories(${CMAKE_SOURCE_DIR}/src)

  add_executable(check_libamf check_libamf.c check_amf0.c)
  target_link_libraries(check_libamf ${CHECK_LIBRARIES} amf pthread)

  add_test(check_libamf ${CMAKE_CURRENT_BINARY_DIR}/check_libamf)
endif (CHECK_FOUND)

# simple demo
add_executable(amf0_demo amf0_demo.c)
target_link_libraries(amf0_demo amf)
