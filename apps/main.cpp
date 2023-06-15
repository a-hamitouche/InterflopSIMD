#include <iostream>
#include <immintrin.h>

#include "simd_interface.h"

int main ()
{
  __m128 a = _mm_set1_ps (0.1f);
  __m128 b = _mm_set1_ps (0.2f);
  __m128 c = _mm_set1_ps (0.0f);

  interflop_simd_interface_t r_interface = init_simd_interface_t();

  r_interface.sse.addf((void*) &a, (void*) &b, (void*) &c, nullptr );

  alignas(32) float res[4];
  _mm_store_ps (res, c);
  for (int i = 0; i < 4; i++)
    std::cout << res[i] << ' ';
  std::cout << std::endl;
  return 0;
}
