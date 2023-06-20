#include <iostream>
#include <immintrin.h>

#include "simd_interface.h"

template<class REG, int N>
void print_res (void * reg)
{
  REG * to_print = reinterpret_cast<REG*>(reg);
  for (int i = 0; i < N; i++)
    {
      std::cout << (*to_print)[i] << ' ';
    }
  std::cout << std::endl;
}

void test_sse (interflop_simd_interface_t& r_interface, float * mem_a, float * mem_b)
{
  __m128 a = _mm_loadu_ps (mem_a);
  __m128 b = _mm_loadu_ps (mem_b);
  __m128 c = _mm_set1_ps (0.0f);

  r_interface.sse.addf((void*) &a, (void*) &b, (void*) &c, nullptr );

  print_res<__m128, 4>((void*) &c);
}

void test_avx (interflop_simd_interface_t& r_interface, float * mem_a, float * mem_b)
{
  __m256 a = _mm256_loadu_ps (mem_a);
  __m256 b = _mm256_loadu_ps (mem_b);
  __m256 c = _mm256_set1_ps (0.0f);

  r_interface.avx.addf((void*) &a, (void*) &b, (void*) &c, nullptr );

  print_res<__m256, 8>((void*) &c);
}

int main ()
{
  // SIMD Interface
  interflop_simd_interface_t r_interface = init_simd_interface_t();


  // Test dataset
  alignas(64) float a[16];
  alignas(64) float b[16];

  for (int i = 0; i < 16; i++)
    {
      a[i] = (float) i;
      b[i] = ((float) i)/10.0f;
    }
  
  test_sse (r_interface, a, b);
  test_avx (r_interface, a, b);
  
  return 0;
}
