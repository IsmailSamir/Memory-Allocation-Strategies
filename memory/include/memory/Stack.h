#pragma once

#include "memory/Exports.h"
#include "memory/block.h"

#include <stdint.h>

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void*))
#endif

namespace mas
{
	typedef struct IStack* Stack;

	MEMORY_EXPORT Stack
	stack_new(size_t memory_size);

	MEMORY_EXPORT void
	stack_free(Stack self);

	inline static void
	destruct(Stack self)
	{
		stack_free(self);
	}

	MEMORY_EXPORT Block
	stack_alloc(Stack self, size_t size, uint8_t align = DEFAULT_ALIGNMENT);
}