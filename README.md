zlstdint
========

Auto C99 integer type compliant (让VC等编译器自动兼容C99的整数类型).


Links:

* Git: https://github.com/zyl910/zlstdint
* Blog: http://www.cnblogs.com/zyl910/tag/zlstdint/

zlstdint is a lightweight C library. Use for auto C99 integer type compliant (用于让VC等编译器自动兼容C99的整数类型) .


References (参考文献) :

* ISO/IEC 9899:1999 - Programming languages -- C (C99). ISO/IEC，1999.
* msinttypes. http://code.google.com/p/msinttypes/


## Usage (用法)

Add `src/``*.*` to you project (将 `src/``*.*` 加入到您的项目).

Example code:

	#define __STDC_LIMIT_MACROS
	#define __STDC_CONSTANT_MACROS
	#define __STDC_FORMAT_MACROS
	
	#include <stdio.h>
	
	#include "z_stdint.h"
	#include "z_inttyp.h"
	
	int main(int argc, char* argv[])
	{
		uint8_t i8 = (uint8_t)INT8_C(-1);
		uint16_t i16 = (uint16_t)INT16_C(-1);
		uint32_t i32 = (uint32_t)INT32_C(-1);
		uint64_t i64 = (uint64_t)INT64_C(-1);
	
		printf("zlstdint:\t%" PRIu8 ", %" PRIu16 ", %" PRIu32 ", %" PRIu64 "\n", i8, i16, i32, i64);
		return 0;
	}

### Config Macro (配置性宏)

* Z_STDINT_H_USESYS: Is use compiler's `stdint.h` (是否使用的是编译器提供的 `stdint.h`) .
* Z_INTTYP_H_USESYS: Is use compiler's `inttypes.h` (是否使用的是编译器提供的 `inttypes.h`) .


## Documentation (文档)

You can generate documentation with [doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) (您可以用doxygen生成文档).

Use doxywizard to open *.doxygen file (使用doxywizard打开 *.doxygen).

* zlstdint_doc.doxygen: Generates documentation from interface files (生成接口的文档) .
* zlstdint_docfull.doxygen: Generates documentation from interface & implement and example files (生成接口、实现、示例等内容的详细文档).

You may need change INCLUDE_PATH in *.doxyfile with the actual location (您可能需要在 *.doxygen 中调整INCLUDE_PATH为实际路径).

## Tested compiler (测试过的编译器)

* Virtual C++: 6, 7.1(2003), 8(2005), 9(2008), 10(2010), 11(2012), 12(2013).
* Turbo C++: Turbo C++ 3, Borland C++ 3.1, C++ Builder 6, C++ Builder XE3 .
* GCC(Linux): 4.7.0~4.8.2(Fedora 17~20), 4.6.3~4.8.2(Ubuntu 12.04~14.04).
* GCC(MinGW): 4.6.2(MinGW(20120426)), 4.7.1~4.9.2(TDM-GCC(MinGW-w64)).
* LLVM GCC: 4.2(Mac OS X Lion 10.7.4), 4.2.1(Mac OS X Mountain Lion 10.8.3).



## Change history (变更日志)

[2015-05-17] zlstdint v1.0

* Release v1.0 (发布1.0版) .

[2013-07-30] c99int v1.2: http://www.cnblogs.com/zyl910/p/c99int_v102.html

* Upload the code to [github](https://github.com/zyl910/c99int) (将代码上传到github).
* Change the directory structure (调整目录结构).
* Add CMake file (添加CMake编译配置文件).
* Using Doxygen style comments (使用doxygen规范注释).
* Fix bug: `__AUTO_STDINT_H_USESYS` (修正 `__AUTO_STDINT_H_USESYS` 误为 `_INTTYPES_H_SYS_` 的bug).

[2013-01-10] c99int v1.1: http://www.cnblogs.com/zyl910/archive/2013/01/10/c99int_v101.html

* Files rename to "auto_stdint.h", "auto_inttypes.h" (文件改名为 "auto_stdint.h", "auto_inttypes.h").
* Check compiler compliant(检测编译器兼容性): Visual C++ 9(2008), Visual C++ 11(2012).

[2012-08-08] c99int v1.0: http://www.cnblogs.com/zyl910/archive/2012/08/08/c99int.html
