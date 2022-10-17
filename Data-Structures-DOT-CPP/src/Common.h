#pragma once

#include <cassert>

#ifdef NDEBUG
	#define ASSERT(x)
#else
	#define ASSERT(x) do { assert((x)); } while(0)
#endif // DEBUG
