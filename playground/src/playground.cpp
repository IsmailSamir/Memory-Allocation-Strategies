#include <iostream>

#include <memory/Stack.h>

#include <vector>

using namespace std;
using namespace msa;


struct Point
{
	size_t x;
	size_t y;
};
int
main(int argc, char** argv)
{

	Stack stack = stack_new(1024);
	
	Point* x = (Point*)stack_alloc(stack, sizeof(Point), alignof(Point)).ptr;
	x->x = 12;
	x->y = 25;


	int* xx = (int*)stack_alloc(stack, sizeof(int), alignof(int)).ptr;
	*xx = 1256;

	float* y = (float*)stack_alloc(stack, sizeof(float), alignof(float)).ptr;
	*y = 12.5;


	stack_free_all(stack);

	Point* k = (Point*)stack_alloc(stack, sizeof(Point), alignof(Point)).ptr;
	k->x = 656;
	k->y = 6332;

	stack_free(stack);

	return 0;
}
