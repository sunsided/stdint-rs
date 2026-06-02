/*
 * Width probe for the toolchain-dependent C99 integer types.
 *
 * This file is never compiled to an object. The crate's build script runs it
 * through the C preprocessor (`cc -E`) using the real target headers. Each `#if`
 * ladder compares a type's `*_MAX` macro against the exact-width `*_MAX` macros
 * and lets exactly one `RUST_STDINT <ctype> <rust-type>` marker line survive.
 * The build script greps for those markers and emits the matching Rust aliases.
 *
 * `RUST_STDINT` is the parse anchor; it must not appear anywhere in <stdint.h>.
 */

#ifdef RUST_STDINT
#error "RUST_STDINT is already defined; cannot use it as a parse anchor"
#endif

#include <stdint.h>

/* ---- signed fast types ---------------------------------------------------- */

#if INT_FAST8_MAX == INT8_MAX
RUST_STDINT int_fast8_t i8
#elif INT_FAST8_MAX == INT16_MAX
RUST_STDINT int_fast8_t i16
#elif INT_FAST8_MAX == INT32_MAX
RUST_STDINT int_fast8_t i32
#elif INT_FAST8_MAX == INT64_MAX
RUST_STDINT int_fast8_t i64
#else
#error "unsupported int_fast8_t width"
#endif

#if INT_FAST16_MAX == INT8_MAX
RUST_STDINT int_fast16_t i8
#elif INT_FAST16_MAX == INT16_MAX
RUST_STDINT int_fast16_t i16
#elif INT_FAST16_MAX == INT32_MAX
RUST_STDINT int_fast16_t i32
#elif INT_FAST16_MAX == INT64_MAX
RUST_STDINT int_fast16_t i64
#else
#error "unsupported int_fast16_t width"
#endif

#if INT_FAST32_MAX == INT8_MAX
RUST_STDINT int_fast32_t i8
#elif INT_FAST32_MAX == INT16_MAX
RUST_STDINT int_fast32_t i16
#elif INT_FAST32_MAX == INT32_MAX
RUST_STDINT int_fast32_t i32
#elif INT_FAST32_MAX == INT64_MAX
RUST_STDINT int_fast32_t i64
#else
#error "unsupported int_fast32_t width"
#endif

#if INT_FAST64_MAX == INT8_MAX
RUST_STDINT int_fast64_t i8
#elif INT_FAST64_MAX == INT16_MAX
RUST_STDINT int_fast64_t i16
#elif INT_FAST64_MAX == INT32_MAX
RUST_STDINT int_fast64_t i32
#elif INT_FAST64_MAX == INT64_MAX
RUST_STDINT int_fast64_t i64
#else
#error "unsupported int_fast64_t width"
#endif

/* ---- unsigned fast types -------------------------------------------------- */

#if UINT_FAST8_MAX == UINT8_MAX
RUST_STDINT uint_fast8_t u8
#elif UINT_FAST8_MAX == UINT16_MAX
RUST_STDINT uint_fast8_t u16
#elif UINT_FAST8_MAX == UINT32_MAX
RUST_STDINT uint_fast8_t u32
#elif UINT_FAST8_MAX == UINT64_MAX
RUST_STDINT uint_fast8_t u64
#else
#error "unsupported uint_fast8_t width"
#endif

#if UINT_FAST16_MAX == UINT8_MAX
RUST_STDINT uint_fast16_t u8
#elif UINT_FAST16_MAX == UINT16_MAX
RUST_STDINT uint_fast16_t u16
#elif UINT_FAST16_MAX == UINT32_MAX
RUST_STDINT uint_fast16_t u32
#elif UINT_FAST16_MAX == UINT64_MAX
RUST_STDINT uint_fast16_t u64
#else
#error "unsupported uint_fast16_t width"
#endif

#if UINT_FAST32_MAX == UINT8_MAX
RUST_STDINT uint_fast32_t u8
#elif UINT_FAST32_MAX == UINT16_MAX
RUST_STDINT uint_fast32_t u16
#elif UINT_FAST32_MAX == UINT32_MAX
RUST_STDINT uint_fast32_t u32
#elif UINT_FAST32_MAX == UINT64_MAX
RUST_STDINT uint_fast32_t u64
#else
#error "unsupported uint_fast32_t width"
#endif

#if UINT_FAST64_MAX == UINT8_MAX
RUST_STDINT uint_fast64_t u8
#elif UINT_FAST64_MAX == UINT16_MAX
RUST_STDINT uint_fast64_t u16
#elif UINT_FAST64_MAX == UINT32_MAX
RUST_STDINT uint_fast64_t u32
#elif UINT_FAST64_MAX == UINT64_MAX
RUST_STDINT uint_fast64_t u64
#else
#error "unsupported uint_fast64_t width"
#endif

/* ---- maximum-width types -------------------------------------------------- */

#if INTMAX_MAX == INT32_MAX
RUST_STDINT intmax_t i32
#elif INTMAX_MAX == INT64_MAX
RUST_STDINT intmax_t i64
#else
#error "unsupported intmax_t width"
#endif

#if UINTMAX_MAX == UINT32_MAX
RUST_STDINT uintmax_t u32
#elif UINTMAX_MAX == UINT64_MAX
RUST_STDINT uintmax_t u64
#else
#error "unsupported uintmax_t width"
#endif
