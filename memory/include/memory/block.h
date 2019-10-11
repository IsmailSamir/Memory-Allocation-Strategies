#pragma once

#include "memory/Exports.h"

#include <stdint.h>

namespace msa
{
	struct Block
	{
		//pointer to the memory block
		void*  ptr;

		//size of the memory block in bytes
		size_t size;

		operator bool() const
		{
			return ptr != nullptr && size != 0;
		}
	};

	template<typename T>
	inline static Block
	block_from(const T& value)
	{
		return Block {(void*)&value, sizeof(T)};
	}

	template<typename T>
	inline static Block
	block_from_ptr(const T* value)
	{
		return Block {(void*)value, sizeof(T)};
	}

	inline static Block
	operator+(const Block& block, size_t offset)
	{
		return Block { (uint8_t*)block.ptr + offset, block.size - offset };
	}

	inline static Block
	operator+(size_t offset, const Block& block)
	{
		return Block { (uint8_t*)block.ptr + offset, block.size - offset };
	}

	inline static Block
	operator-(const Block& block, size_t offset)
	{
		return Block { (uint8_t*)block.ptr - offset, block.size + offset };
	}

	inline static Block
	operator-(size_t offset, const Block& block)
	{
		return Block { (uint8_t*)block.ptr - offset, block.size + offset };
	}
}
