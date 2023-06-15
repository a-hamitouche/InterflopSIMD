# Liste des fichiers source
set(SSE_LIBSIMD_SOURCES
  sse.cpp
  )

add_compile_options(-msse4.1 -mno-vzeroupper)
add_library(sse_obj OBJECT ${SSE_LIBSIMD_SOURCES})

# Création de la bibliothèque libsimd
add_compile_options(-fno-lto)
add_library(LibSimd STATIC $<TARGET_OBJECTS:sse_obj>)

# Chemin d'inclusion des fichiers d'entête
target_include_directories(LibSimd PUBLIC ${CMAKE_SOURCE_DIR}/inc/libsimd)
