set(APP_SOURCE
  main.cpp
  )

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_compile_options(-mavx2 -fno-lto)
add_executable(test_interface ${APP_SOURCE})

target_link_libraries(test_interface interface_obj LibSimd)
