#include <immintrin.h>

void addf32_8_avx (__m256* a, __m256* b, __m256* c, void* ctx)
{
  *c = _mm256_add_ps (*a, *b);
}
