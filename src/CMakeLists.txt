set(INTERFACE_SOURCE
  simd_interface.cpp
  )

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_library(interface_obj OBJECT ${INTERFACE_SOURCE})

target_include_directories(interface_obj PUBLIC ${CMAKE_SOURCE_DIR}/inc)
