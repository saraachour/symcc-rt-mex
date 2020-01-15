// Run-time library interface                                  -*- C++ -*-
//
// This header defines the interface of the run-time library. It is not actually
// used anywhere because the compiler pass inserts calls to the library
// functions at the level of LLVM bitcode, but it serves as documentation of the
// intended interface.
//
// Whoever uses this file has to define the type "SymExpr" first; we use it to
// keep this header independent of the back-end implementation.

#ifndef RUNTIMECOMMON_H
#define RUNTIMECOMMON_H

#include <cstdint>

extern "C" {
/*
 * Initialization
 */
void _sym_initialize(void);

/*
 * Interface for programs
 */
uint32_t sym_make_symbolic(const char *name, uint32_t value, uint8_t bits);

/*
 * Construction of simple values
 */
SymExpr _sym_build_integer(uint64_t value, uint8_t bits);
SymExpr _sym_build_integer128(unsigned __int128 value);
SymExpr _sym_build_float(double value, int is_double);
SymExpr _sym_build_null_pointer();
SymExpr _sym_build_true();
SymExpr _sym_build_false();
SymExpr _sym_build_bool(bool value);

/*
 * Arithmetic and shifts
 */
SymExpr _sym_build_add(SymExpr a, SymExpr b);
SymExpr _sym_build_sub(SymExpr a, SymExpr b);
SymExpr _sym_build_mul(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_div(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_div(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_shift_left(SymExpr a, SymExpr b);
SymExpr _sym_build_logical_shift_right(SymExpr a, SymExpr b);
SymExpr _sym_build_arithmetic_shift_right(SymExpr a, SymExpr b);

SymExpr _sym_build_fp_add(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_sub(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_mul(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_div(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_rem(SymExpr a, SymExpr b);
SymExpr _sym_build_fp_abs(SymExpr a);

/*
 * Boolean operations
 */
SymExpr _sym_build_neg(SymExpr expr);
SymExpr _sym_build_signed_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_signed_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_unsigned_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_not_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_and(SymExpr a, SymExpr b);
SymExpr _sym_build_and(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_or(SymExpr a, SymExpr b);
SymExpr _sym_build_or(SymExpr a, SymExpr b);
SymExpr _sym_build_bool_xor(SymExpr a, SymExpr b);
SymExpr _sym_build_xor(SymExpr a, SymExpr b);

SymExpr _sym_build_float_ordered_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered_not_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_ordered(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_greater_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_greater_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_less_than(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_less_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_equal(SymExpr a, SymExpr b);
SymExpr _sym_build_float_unordered_not_equal(SymExpr a, SymExpr b);

/*
 * Casts
 */
SymExpr _sym_build_sext(SymExpr expr, uint8_t bits);
SymExpr _sym_build_zext(SymExpr expr, uint8_t bits);
SymExpr _sym_build_trunc(SymExpr expr, uint8_t bits);
SymExpr _sym_build_bswap(SymExpr expr);
SymExpr _sym_build_int_to_float(SymExpr value, int is_double, int is_signed);
SymExpr _sym_build_float_to_float(SymExpr expr, int to_double);
SymExpr _sym_build_bits_to_float(SymExpr expr, int to_double);
SymExpr _sym_build_float_to_bits(SymExpr expr);
SymExpr _sym_build_float_to_signed_integer(SymExpr expr, uint8_t bits);
SymExpr _sym_build_float_to_unsigned_integer(SymExpr expr, uint8_t bits);
SymExpr _sym_build_bool_to_bits(SymExpr expr, uint8_t bits);

/*
 * Bit-array helpers
 */
SymExpr _sym_concat_helper(SymExpr a, SymExpr b);
SymExpr _sym_extract_helper(SymExpr expr, size_t first_bit, size_t last_bit);
size_t _sym_bits_helper(SymExpr expr);

/*
 * Function-call helpers
 */
void _sym_set_parameter_expression(uint8_t index, SymExpr expr);
SymExpr _sym_get_parameter_expression(uint8_t index);
void _sym_set_return_expression(SymExpr expr);
SymExpr _sym_get_return_expression(void);

/*
 * Constraint handling
 */
void _sym_push_path_constraint(SymExpr constraint, int taken,
                               uintptr_t site_id);
SymExpr _sym_get_input_byte(size_t offset);

/*
 * Memory management
 */
SymExpr _sym_read_memory(uint8_t *addr, size_t length, bool little_endian);
void _sym_write_memory(uint8_t *addr, size_t length, SymExpr expr,
                       bool little_endian);
void _sym_memcpy(uint8_t *dest, const uint8_t *src, size_t length);
void _sym_memset(uint8_t *memory, SymExpr value, size_t length);
void _sym_memmove(uint8_t *dest, const uint8_t *src, size_t length);
SymExpr _sym_build_extract(SymExpr expr, uint64_t offset, uint64_t length,
                           bool little_endian);

/*
 * Call-stack tracing
 */
void _sym_notify_call(uintptr_t site_id);
void _sym_notify_ret(uintptr_t site_id);
void _sym_notify_basic_block(uintptr_t site_id);
}

#endif
