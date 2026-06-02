#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#if defined(_MSC_VER)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#else
#include <sys/types.h>
#endif

typedef size_t _size_t;
typedef ssize_t _ssize_t;
typedef intptr_t _intptr_t;
typedef uintptr_t _uintptr_t;

const int64_t RUST_STDINT_INT64_MIN = INT64_MIN;
const int64_t RUST_STDINT_INT64_MAX = INT64_MAX;

const int_fast64_t RUST_STDINT_INT_FAST64_MIN = INT_FAST64_MIN;
const int_fast64_t RUST_STDINT_INT_FAST64_MAX = INT_FAST64_MAX;

const int_least64_t RUST_STDINT_INT_LEAST64_MIN = INT_LEAST64_MIN;
const int_least64_t RUST_STDINT_INT_LEAST64_MAX = INT_LEAST64_MAX;

const intmax_t RUST_STDINT_INTMAX_MIN = INTMAX_MIN;
const intmax_t RUST_STDINT_INTMAX_MAX = INTMAX_MAX;
