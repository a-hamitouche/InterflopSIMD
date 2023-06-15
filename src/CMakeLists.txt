set(INTERFACE_SOURCE
  simd_interface.cpp
  )

add_subdirectory(libsimd)

include_directories(${CMAKE_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/inc/libsimd)
add_library(interface_obj OBJECT ${INTERFACE_SOURCE})

target_include_directories(interface_obj PUBLIC ${CMAKE_SOURCE_DIR}/inc)
