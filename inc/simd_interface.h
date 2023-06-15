#pragma once

typedef struct
{
  void (*addf)(void*, void*, void*, void*);
} interflop_op_t;

typedef struct
{
  interflop_op_t sse;
} interflop_simd_interface_t;

void addf32_4 (void* a, void* b, void* c, void* ctx);

interflop_op_t init_simd_op_t ();

interflop_simd_interface_t init_simd_interface_t ();
