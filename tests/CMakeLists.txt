include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(amf0_demo amf0_demo.c)
target_link_libraries(amf0_demo amf)
