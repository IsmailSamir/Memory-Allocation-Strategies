#include <iostream>

#include <memory/memory.h>

using namespace std;
using namespace msa;

int
main(int argc, char** argv)
{
	Arena arena = arena_new(20);

	arena_alloc(arena, 4, alignof(int));
	arena_alloc(arena, 1, alignof(char));
	arena_alloc(arena, 8, alignof(double));
	arena_alloc(arena, 2, alignof(short));

	arena_free_all(arena);
	arena_free(arena);

	return 0;
}
