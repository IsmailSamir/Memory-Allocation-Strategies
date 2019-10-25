#include "memory/Pool.h"
#include "memory/Arena.h"
#include "memory/block.h"

#include <malloc.h>
#include <string.h>
#include <assert.h>

namespace msa
{
	struct IPool
	{
		Arena arena;
		void* head;
		size_t element_size;
	};

	Pool
	pool_new(size_t element_size, size_t bucket_size)
	{
		Pool self = (Pool)::malloc(sizeof(IPool));

		if (element_size < sizeof(void*))
			element_size = sizeof(void*);

		self->arena = arena_new(element_size * bucket_size);
		self->head = nullptr;
		self->element_size = element_size;

		return self;
	}

	void
	pool_free(Pool self)
	{
		arena_free(self->arena);
		::free(self);
	}

	void*
	pool_get(Pool self)
	{
		if (self->head != nullptr)
		{
			void* ptr = self->head;
			self->head = nullptr;
			return ptr;
		}

		return arena_alloc(self->arena, self->element_size, alignof(char)).ptr;
	}

	void
	pool_put(Pool self, void * ptr)
	{
		self->head = ptr;
	}
}