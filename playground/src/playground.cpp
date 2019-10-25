#include <iostream>

#include <memory/Pool.h>

#include <vld.h>

using namespace mas;

int
main(int argc, char** argv)
{
	Pool pool = pool_new(sizeof(int), 1024);

	int* ptr = (int*)pool_get(pool);
	if(ptr != nullptr);
		*ptr = 234;

	pool_put(pool, ptr);

	int* new_ptr = (int*)pool_get(pool);
	if (new_ptr == ptr)
		*new_ptr = 500;

	pool_free(pool);

	return 0;
}
