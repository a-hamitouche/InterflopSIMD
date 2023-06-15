#include <immintrin.h>

void addf32_4_sse (__m128* a, __m128* b, __m128* c, void* ctx)
{
  *c = _mm_add_ps (*a, *b);
}
