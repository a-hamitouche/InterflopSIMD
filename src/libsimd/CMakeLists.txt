# Liste des fichiers source
set(SSE_LIBSIMD_SOURCES
  sse.cpp
  )

set(AVX_LIBSIMD_SOURCES
  avx.cpp
  )

add_compile_options(-msse4.1 -mno-vzeroupper)
add_library(sse_obj OBJECT ${SSE_LIBSIMD_SOURCES})

add_compile_options(-mavx2 -mno-vzeroupper)
add_library(avx_obj OBJECT ${AVX_LIBSIMD_SOURCES})

# Création de la bibliothèque libsimd
add_compile_options(-fno-lto)
add_library(LibSimd STATIC $<TARGET_OBJECTS:sse_obj> $<TARGET_OBJECTS:avx_obj>)

# Chemin d'inclusion des fichiers d'entête
target_include_directories(LibSimd PUBLIC ${CMAKE_SOURCE_DIR}/inc/libsimd)
