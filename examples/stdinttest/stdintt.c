/** @addtogroup GROUP_ZYLLIBC	zyllibc
 * @{
 */

/** @addtogroup GROUP_ZLSTDINT	zlstdint
 * @{
 */

/** @addtogroup GROUP_ZLSTDINT_STDINTTEST	stdinttest
 * Test zlstdint (测试C99整数类型).
 *
 * @author	[zyl910](mailto:zyl910hero@gmail.com)
 * @since	@ref GROUP_ZLSTDINT 1.0
 * @version	1.0
 * @date	2015-05-17
 *
 * Links:
 *
 * * Git: https://github.com/zyl910/zlstdint
 * * Blog: http://www.cnblogs.com/zyl910/tag/zlstdint/
 *
 *
 *
 * ## Change history (变更日志)
 *
 * [2015-05-17] v1.0
 *
 * * V1.0发布.
 *
 * @{
 */

/**
 * @file	stdintt.c
 * @brief	Test zlstdint (测试C99整数类型).
 * @since	@ref GROUP_ZLSTDINT 1.0
 */

#define __STDC_LIMIT_MACROS	//!< C++ implementations should define these macros only when __STDC_LIMIT_MACROS is defined before <stdint.h>is included.
#define __STDC_CONSTANT_MACROS	//!< C++ implementations should define these macros only when __STDC_CONSTANT_MACROS is defined before <stdint.h>is included.
#define __STDC_FORMAT_MACROS	//!< C++ implementations should define these macros only when __STDC_FORMAT_MACROSis defined before <inttypes.h>is included.

#include <stdio.h>

#include "z_stdint.h"
#include "z_inttyp.h"

/// main.
int main(int argc, char* argv[]) {
	uint8_t i8 = (uint8_t)INT8_C(-1);
	uint16_t i16 = (uint16_t)INT16_C(-1);
	uint32_t i32 = (uint32_t)INT32_C(-1);
#ifdef INT64_MAX
	uint64_t i64 = (uint64_t)INT64_C(-1);
#endif

#ifdef INT64_MAX
	printf("stdint:\t%" PRIu8 ", %" PRIu16 ", %" PRIu32 ", %" PRIu64 "\n", i8, i16, i32, i64);
#else
	printf("stdint:\t%" PRIu8 ", %" PRIu16 ", %" PRIu32 "\n", i8, i16, i32);
#endif
	return 0;
}


/** @} */	// @addtogroup GROUP_ZLSTDINT_STDINTTEST
/** @} */	// @addtogroup GROUP_ZLSTDINT
/** @} */	// @addtogroup GROUP_ZYLLIBC
