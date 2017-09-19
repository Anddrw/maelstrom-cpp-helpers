#pragma once

#include <cstdint>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdarg.h>

using namespace std;

namespace maelstrom
{
	typedef uint32_t uint32;
	typedef uint64_t uint64;
	typedef uint16_t uint16;
	typedef int32_t  int32;
	typedef int64_t  int64;
	typedef int16_t  int16;
	typedef size_t   size;

	class random;
	class hash;
	class filesystem;
	class debugging;
	class dt;
	class unit;
	class charset;
}
