#pragma once

#include "memory/Exports.h"
#include "memory/block.h"

#include <stdint.h>

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void*))
#endif

namespace mas
{
	typedef struct IPool* Pool;

	MEMORY_EXPORT Pool
	pool_new(size_t element_size, size_t bucket_size);

	MEMORY_EXPORT void
	pool_free(Pool self);

	inline static void
	destruct(Pool self)
	{
		pool_free(self);
	}

	MEMORY_EXPORT void*
	pool_get(Pool self);

	MEMORY_EXPORT void
	pool_put(Pool self, void* ptr);
}