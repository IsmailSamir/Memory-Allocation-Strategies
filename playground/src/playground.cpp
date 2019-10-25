#include <iostream>

#include <memory/Arena.h>

#include <vld.h>

using namespace msa;

struct Point
{
	size_t x;
	size_t y;
};
int
main(int argc, char** argv)
{

	 Arena arena = arena_new(1024);
	
	Point* x = (Point*)arena_alloc(arena, sizeof(Point), alignof(Point)).ptr;
	x->x = 12;
	x->y = 25;


	int* xx = (int*)arena_alloc(arena, sizeof(int), alignof(int)).ptr;
	*xx = 1256;

	float* y = (float*)arena_alloc(arena, sizeof(float), alignof(float)).ptr;
	*y = 12.5;

	Point* k = (Point*)arena_alloc(arena, sizeof(Point), alignof(Point)).ptr;
	k->x = 656;
	k->y = 6332;

	arena_free(arena);

	return 0;
}
