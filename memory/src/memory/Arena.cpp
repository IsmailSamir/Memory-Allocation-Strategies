#include "memory/Arena.h"
#include "memory/block.h"

#include <malloc.h>
#include <string.h>
#include <assert.h>

namespace msa
{
	struct Node
	{
		Block memory;
		uint8_t* head;
		Node* next;
	};

	struct IArena
	{
		Node* root;
		size_t block_size;
		size_t used_memory;
		size_t total_memory;
	};

	Arena
	arena_new(size_t block_size)
	{
		Arena self = (Arena)::malloc(sizeof(IArena));

		self->root = nullptr;
		self->block_size = block_size;
		self->used_memory = 0;
		self->total_memory = 0;

		return self;
	}

	void
	arena_free(Arena self)
	{
		Node* tmp = self->root;
		while (tmp != nullptr)
		{
			tmp = tmp->next;
			::free(self->root->memory.ptr);
			::free(self->root);
			self->root = tmp;
		}

		::free(self);
	}

	inline static void
	grow(Arena self, size_t size)
	{
		if (self->root != nullptr)
		{
			size_t used_memory = self->root->head - (uint8_t*)self->root->memory.ptr;
			size_t free_memory = self->root->memory.size - used_memory;
			if (free_memory >= size)
				return;
		}

		size_t request_size = size > self->block_size ? size : self->block_size;

		Node* node = (Node*)::malloc(sizeof(Node));
		node->memory.ptr = ::malloc(request_size);
		node->memory.size = request_size;
		node->head = (uint8_t*)node->memory.ptr;
		node->next = self->root;

		self->root = node;
		self->used_memory += size;
		self->total_memory += request_size;
	}

	Block
	arena_alloc(Arena self, size_t size, uint8_t align)
	{
		grow(self, size);

		uint8_t* ptr = (uint8_t*)self->root->head;
		self->root->head += size;

		::memset(ptr, 0, size);

		return Block{ ptr, size };
	}
}