#ifndef UTIL_H
#define UTIL_H

#define CHECK_int8_t_BOUNDS(val)              	 ((val) >= INT8_MIN && (val) <= INT8_MAX)
#define CHECK_uint8_t_BOUNDS(val)             	 ((val) >= 0 && (val) <= UINT8_MAX)
#define CHECK_int16_t_BOUNDS(val)             	 ((val) >= INT16_MIN && (val) <= INT16_MAX)
#define CHECK_uint16_t_BOUNDS(val)            	 ((val) >= 0 && (val) <= UINT16_MAX)
#define CHECK_int32_t_BOUNDS(val)             	 ((val) >= INT32_MIN && (val) <= INT32_MAX)
#define CHECK_uint32_t_BOUNDS(val)            	 ((val) >= 0 && (val) <= UINT32_MAX)
#define CHECK_int64_t_BOUNDS(val)             	 ((val) >= INT64_MIN && (val) <= INT64_MAX)
#define CHECK_uint64_t_BOUNDS(val)            	 ((val) >= 0 && (val) <= UINT64_MAX)
#define CHECK_char_BOUNDS(val)                  ((val) >= CHAR_MIN && (val) <= CHAR_MAX)
#define CHECK_short_BOUNDS(val)                 ((val) >= SHRT_MIN && (val) <= SHRT_MAX)
#define CHECK_int_BOUNDS(val)                   ((val) >= INT_MIN && (val) <= INT_MAX)
#define CHECK_long_BOUNDS(val)                  ((val) >= LONG_MIN && (val) <= LONG_MAX)
#define CHECK_unsigned_BOUNDS(val)              ((val) >= 0 && (val) <= ULONG_MAX)
#define CHECK_TYPE_BOUNDS(val, TYPE)            CHECK_##TYPE##_BOUNDS(val)
#define SAFE_CAST(val, TYPE)                    (CHECK_TYPE_BOUNDS(val, TYPE) ? (TYPE)(val) : (TYPE)0)

#define GUARD_OOB(val, min, max)                do { if ((val) < (min) || (val) > (max)) { goto cleanup; } } while (0)
#define GUARD_NULL(ptr)                         do { if (!(ptr)) { goto cleanup; } } while (0)
#define GUARD_TRUE(expr)                        do { if ((expr)) { goto cleanup; } } while (0)
#define GUARD_FALSE(expr)                       do { if (!(expr)) { goto cleanup; } } while (0)
#define GUARD_POS(val)                          do { if ((val) > 0) { goto cleanup; } } while (0)
#define GUARD_NEG(val)                          do { if ((val) < 0) { goto cleanup; } } while (0)
#define GUARD_ZERO(val)                         do { if ((val) == 0) { goto cleanup; } } while (0)
#define GUARD_NON_POS(val)                      do { if ((val) <= 0) { goto cleanup; } } while (0)
#define GUARD_NON_NEG(val)                      do { if ((val) >= 0) { goto cleanup; } } while (0)
#define GUARD_NON_ZERO(val)                     do { if ((val) != 0) { goto cleanup; } } while (0)
#define GUARD_ERROR(expr)                       GUARD_TRUE(expr)

#define ZERO_MEM(ptr, size)						memset(ptr, 0, size)	
#define FREE(ptr)								if ((ptr)) { free(ptr); ptr = NULL; }

typedef u8 unsigned short; 

int print_chars(const char * const str, const uint8_t len);
int arrncpy(int8_t * const dst, const int8_t * const src, const uint8_t len);

#endif
