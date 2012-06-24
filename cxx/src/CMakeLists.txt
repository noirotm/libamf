set(LIBAMF_SRC
  data.cpp
  ${CMAKE_SOURCE_DIR}/include/amf/data.hpp
  null.hpp
)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(amf STATIC ${LIBAMF_SRC})