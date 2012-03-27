set(LIBAMF_SRC
  data.cpp
  ${CMAKE_SOURCE_DIR}/include/amf/data.hpp
  ${CMAKE_SOURCE_DIR}/include/amf/data_handler.hpp
  null_handler.cpp
  null_handler.hpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(amf STATIC ${LIBAMF_SRC})