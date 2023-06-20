#include "simd_interface.h"

#if defined(__x86_64)

#include "sse.h"
#include "avx.h"

typedef __m128 vec_float32_t;
typedef __m256 vec_float32x2_t;

#endif

void addf32_4 (void* a, void* b, void* c, void* ctx)
{
  addf32_4_sse ((vec_float32_t*) a, (vec_float32_t*) b, (vec_float32_t*) c, ctx);
}

void addf32_8 (void* a, void* b, void* c, void* ctx)
{
  addf32_8_avx ((vec_float32x2_t*) a, (vec_float32x2_t*) b, (vec_float32x2_t*) c, ctx);
}

interflop_op_t init_simd_op_t (int r_size)
{
  if (r_size == 256)
    return (interflop_op_t) {.addf = addf32_8};
  return (interflop_op_t) {.addf = addf32_4};
}

interflop_simd_interface_t init_simd_interface_t ()
{
  return (interflop_simd_interface_t) {
    .sse = init_simd_op_t(128),
    .avx = init_simd_op_t(256)
  };
}
