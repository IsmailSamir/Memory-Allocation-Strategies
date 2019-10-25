#pragma once

#include "memory/Exports.h"
#include "memory/block.h"

#include <stdint.h>

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void*))
#endif

namespace mas
{
	typedef struct IArena* Arena;

	MEMORY_EXPORT Arena
	arena_new(size_t block_size);

	MEMORY_EXPORT void
	arena_free(Arena self);

	inline static void
	destruct(Arena self)
	{
		arena_free(self);
	}

	MEMORY_EXPORT Block
	arena_alloc(Arena self, size_t size, uint8_t align);

}