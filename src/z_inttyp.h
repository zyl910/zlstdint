/// @addtogroup GROUP_ZYLLIBC	zyllibc
/// @{
///

/// @addtogroup GROUP_ZLSTDINT	zlstdint
/// @{
///

///
/// @file	z_inttyp.h
/// @brief	Auto include C99 inttypes.h (使各种编译器兼容 `inttypes.h`).
/// @since	@ref GROUP_ZLSTDINT 1.0
///
/// Features(特性):
///
/// * Auto support `inttypes.h` (使各种编译器兼容 `inttypes.h`).
/// * Z_INTTYP_H_USESYS: Is use compiler's `inttypes.h` (是否使用的是编译器提供的 `inttypes.h`) .
///
/// References (参考文献) :
///
/// * ISO/IEC 9899:1999 - Programming languages -- C (C99). ISO/IEC，1999.
///

#ifndef INCLUDED_Z_INTTYP_H
#define INCLUDED_Z_INTTYP_H

/// @def Z_INTTYP_H_USESYS
/// Is use compiler's `inttypes.h` (是否使用的是编译器提供的 `inttypes.h`) .
#ifndef Z_INTTYP_H_USESYS
#if defined(__GNUC__)	// GCC.
	#define Z_INTTYP_H_USESYS	1
#elif defined(_MSC_VER)	// MSVC. VC2012仍不支持.
	#define Z_INTTYP_H_USESYS	0
#elif defined(__BORLANDC__)	// BCB. BCB6~CBXE3仍不支持.
	#define Z_INTTYP_H_USESYS	0
#else
	// 假定其他不支持.
	#define Z_INTTYP_H_USESYS	0
#endif
#endif	// #ifndef Z_INTTYP_H_USESYS.


#if Z_INTTYP_H_USESYS
// 使用编译器提供的<inttypes.h>
#include <inttypes.h>
#else
// 采用自定义的inttypes.h. 参考了 msinttypes: http://code.google.com/p/msinttypes/

#ifndef _MSC_INTTYPES_H_ // [
#define _MSC_INTTYPES_H_

//#include "stdint.h"
#include "z_stdint.h"

// 7.8 Format conversion of integer types

typedef struct {
   intmax_t quot;
   intmax_t rem;
} imaxdiv_t;

// 7.8.1 Macros for format specifiers

#if !defined(__cplusplus) || defined(__STDC_FORMAT_MACROS) // [   See footnote 185 at page 198

// The fprintf macros for signed integers are:
#define PRId8       "d"
#define PRIi8       "i"
#define PRIdLEAST8  PRId8
#define PRIiLEAST8  PRIi8
#define PRIdFAST8   PRIdFAST8
#define PRIiFAST8   PRIiFAST8

#define PRId16       "hd"
#define PRIi16       "hi"
#define PRIdLEAST16  PRId16
#define PRIiLEAST16  PRIi16
#define PRIdFAST16   PRId16
#define PRIiFAST16   PRIi16

#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRId32       "I32d"
#define PRIi32       "I32i"
#elif INT_MAX >= INT32_MAX
#define PRId32       "d"
#define PRIi32       "i"
#else
#define PRId32       "ld"
#define PRIi32       "li"
#endif
#define PRIdLEAST32  PRId32
#define PRIiLEAST32  PRIi32
#define PRIdFAST32   PRId32
#define PRIiFAST32   PRIi32

#if AUTO_STDINT_INTMAX_BIT >= 64
#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRId64       "I64d"
#define PRIi64       "I64i"
#elif LONG_MAX >= INT64_MAX
#define PRId64       "ld"
#define PRIi64       "li"
#else
#define PRId64       "lld"
#define PRIi64       "lli"
#endif
#define PRIdLEAST64  PRId64
#define PRIiLEAST64  PRIiLEAST64
#define PRIdFAST64   PRId64
#define PRIiFAST64   PRIiLEAST64
#endif

#if AUTO_STDINT_INTMAX_BIT >= 64
#define PRIdMAX     PRId64
#define PRIiMAX     PRIi64
#else
#define PRIdMAX     PRId32
#define PRIiMAX     PRIi32
#endif

#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRIdPTR     "Id"
#define PRIiPTR     "Ii"
#else
#define PRIdPTR     "d"
#define PRIiPTR     "i"
#endif

// The fprintf macros for unsigned integers are:
#define PRIo8       "o"
#define PRIu8       "u"
#define PRIx8       "x"
#define PRIX8       "X"
#define PRIoLEAST8  PRIo8
#define PRIuLEAST8  PRIu8
#define PRIxLEAST8  PRIx8
#define PRIXLEAST8  PRIX8
#define PRIoFAST8   PRIo8
#define PRIuFAST8   PRIu8
#define PRIxFAST8   PRIx8
#define PRIXFAST8   PRIX8

#define PRIo16       "ho"
#define PRIu16       "hu"
#define PRIx16       "hx"
#define PRIX16       "hX"
#define PRIoLEAST16  PRIo16
#define PRIuLEAST16  PRIu16
#define PRIxLEAST16  PRIx16
#define PRIXLEAST16  PRIX16
#define PRIoFAST16   PRIo16
#define PRIuFAST16   PRIu16
#define PRIxFAST16   PRIx16
#define PRIXFAST16   PRIX16

#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRIo32       "I32o"
#define PRIu32       "I32u"
#define PRIx32       "I32x"
#define PRIX32       "I32X"
#elif INT_MAX >= INT32_MAX
#define PRIo32       "o"
#define PRIu32       "u"
#define PRIx32       "x"
#define PRIX32       "X"
#else
#define PRIo32       "lo"
#define PRIu32       "lu"
#define PRIx32       "lx"
#define PRIX32       "lX"
#endif
#define PRIoLEAST32  PRIo32
#define PRIuLEAST32  PRIu32
#define PRIxLEAST32  PRIx32
#define PRIXLEAST32  PRIX32
#define PRIoFAST32   PRIo32
#define PRIuFAST32   PRIu32
#define PRIxFAST32   PRIx32
#define PRIXFAST32   PRIX32

#if AUTO_STDINT_INTMAX_BIT >= 64
#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRIo64       "I64o"
#define PRIu64       "I64u"
#define PRIx64       "I64x"
#define PRIX64       "I64X"
#elif LONG_MAX >= INT64_MAX
#define PRIo64       "lo"
#define PRIu64       "lu"
#define PRIx64       "lx"
#define PRIX64       "lX"
#else
#define PRIo64       "llo"
#define PRIu64       "llu"
#define PRIx64       "llx"
#define PRIX64       "llX"
#endif
#define PRIoLEAST64  PRIo64
#define PRIuLEAST64  PRIu64
#define PRIxLEAST64  PRIx64
#define PRIXLEAST64  PRIX64
#define PRIoFAST64   PRIo64
#define PRIuFAST64   PRIu64
#define PRIxFAST64   PRIx64
#define PRIXFAST64   PRIX64
#endif

#if AUTO_STDINT_INTMAX_BIT >= 64
#define PRIoMAX     PRIo64
#define PRIuMAX     PRIu64
#define PRIxMAX     PRIx64
#define PRIXMAX     PRIX64
#else
#define PRIoMAX     PRIo32
#define PRIuMAX     PRIu32
#define PRIxMAX     PRIx32
#define PRIXMAX     PRIX32
#endif

#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define PRIoPTR     "Io"
#define PRIuPTR     "Iu"
#define PRIxPTR     "Ix"
#define PRIXPTR     "IX"
#else
#define PRIoPTR     "o"
#define PRIuPTR     "u"
#define PRIxPTR     "x"
#define PRIXPTR     "X"
#endif

// The fscanf macros for signed integers are:
#define SCNd8       PRId8
#define SCNi8       PRIi8
#define SCNdLEAST8  PRIdLEAST8
#define SCNiLEAST8  PRIiLEAST8
#define SCNdFAST8   PRIdFAST8
#define SCNiFAST8   PRIiFAST8

#define SCNd16       PRId16
#define SCNi16       PRIi16
#define SCNdLEAST16  PRIdLEAST16
#define SCNiLEAST16  PRIiLEAST16
#define SCNdFAST16   PRIdFAST16
#define SCNiFAST16   PRIiFAST16

#define SCNd32       PRId32
#define SCNi32       PRIi32
#define SCNdLEAST32  PRIdLEAST32
#define SCNiLEAST32  PRIiLEAST32
#define SCNdFAST32   PRIdFAST32
#define SCNiFAST32   PRIiFAST32

#define SCNd64       PRId64
#define SCNi64       PRIi64
#define SCNdLEAST64  PRIdLEAST64
#define SCNiLEAST64  PRIiLEAST64
#define SCNdFAST64   PRIdFAST64
#define SCNiFAST64   PRIiFAST64

#define SCNdMAX     PRIdMAX
#define SCNiMAX     PRIiMAX

#define SCNdPTR     PRIdPTR
#define SCNiPTR     PRIiPTR

// The fscanf macros for unsigned integers are:
#define SCNo8       PRIo8
#define SCNu8       PRIu8
#define SCNx8       PRIx8
#define SCNX8       PRIX8
#define SCNoLEAST8  PRIoLEAST8
#define SCNuLEAST8  PRIuLEAST8
#define SCNxLEAST8  PRIxLEAST8
#define SCNXLEAST8  PRIXLEAST8
#define SCNoFAST8   PRIoFAST8
#define SCNuFAST8   PRIuFAST8
#define SCNxFAST8   PRIxFAST8
#define SCNXFAST8   PRIXFAST8

#define SCNo16       PRIo16
#define SCNu16       PRIu16
#define SCNx16       PRIx16
#define SCNX16       PRIX16
#define SCNoLEAST16  PRIoLEAST16
#define SCNuLEAST16  PRIuLEAST16
#define SCNxLEAST16  PRIxLEAST16
#define SCNXLEAST16  PRIXLEAST16
#define SCNoFAST16   PRIoFAST16
#define SCNuFAST16   PRIuFAST16
#define SCNxFAST16   PRIxFAST16
#define SCNXFAST16   PRIXFAST16

#define SCNo32       PRIo32
#define SCNu32       PRIu32
#define SCNx32       PRIx32
#define SCNX32       PRIX32
#define SCNoLEAST32  PRIoLEAST32
#define SCNuLEAST32  PRIuLEAST32
#define SCNxLEAST32  PRIxLEAST32
#define SCNXLEAST32  PRIXLEAST32
#define SCNoFAST32   PRIoFAST32
#define SCNuFAST32   PRIuFAST32
#define SCNxFAST32   PRIxFAST32
#define SCNXFAST32   PRIXFAST32

#define SCNo64       PRIo64
#define SCNu64       PRIu64
#define SCNx64       PRIx64
#define SCNX64       PRIX64
#define SCNoLEAST64  PRIoLEAST64
#define SCNuLEAST64  PRIuLEAST64
#define SCNxLEAST64  PRIxLEAST64
#define SCNXLEAST64  PRIXLEAST64
#define SCNoFAST64   PRIoFAST64
#define SCNuFAST64   PRIuFAST64
#define SCNxFAST64   PRIxFAST64
#define SCNXFAST64   PRIXFAST64

#define SCNoMAX     PRIoMAX
#define SCNuMAX     PRIuMAX
#define SCNxMAX     PRIxMAX
#define SCNXMAX     PRIXMAX

#define SCNoPTR     PRIoPTR
#define SCNuPTR     PRIuPTR
#define SCNxPTR     PRIxPTR
#define SCNXPTR     PRIXPTR
#endif // __STDC_FORMAT_MACROS ]

// 7.8.2 Functions for greatest-width integer types

// 7.8.2.1 The imaxabs function
#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define imaxabs _abs64
#else
#define imaxabs labs
#endif

// 7.8.2.2 The imaxdiv function

#ifdef _MSC_VER
// This is modified version of div() function from Microsoft's div.c found
// in %MSVC.NET%\crt\src\div.c
#ifdef STATIC_IMAXDIV // [
static
#else // STATIC_IMAXDIV ][
_inline
#endif // STATIC_IMAXDIV ]
imaxdiv_t __cdecl imaxdiv(intmax_t numer, intmax_t denom)
{
   imaxdiv_t result;

   result.quot = numer / denom;
   result.rem = numer % denom;

   if (numer < 0 && result.rem > 0) {
      // did division wrong; must fix up
      ++result.quot;
      result.rem -= denom;
   }

   return result;
}
#endif  // #ifdef _MSC_VER

// 7.8.2.3 The strtoimax and strtoumax functions
#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define strtoimax _strtoi64
#define strtoumax _strtoui64
#else
#define strtoimax strtol
#define strtoumax strtoul
#endif

// 7.8.2.4 The wcstoimax and wcstoumax functions
#if defined(_MSC_VER) && _MSC_VER>1200	// > VC6
#define wcstoimax _wcstoi64
#define wcstoumax _wcstoui64
#else
#define wcstoimax wcstol
#define wcstoumax wcstoul
#endif


#endif // _MSC_INTTYPES_H_ ]

#endif // #ifdef Z_INTTYP_H_USESYS

#endif // #ifndef INCLUDED_Z_INTTYP_H


/// @}
/// @}
