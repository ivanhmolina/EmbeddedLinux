#include <stdio.h>
#include <stdlib.h>

int oldname = 5;

extern int newname __attribute__((alias("oldname")));

static int myfunc(int a, int b)
{
	printf("%s: Adding %d with %d:\t Result: %d\n", __func__, a, b, a+b);
	return a+b;
}

static int add(int a, int b) __attribute__((alias("myfunc")));

int main()
{
	add(3,6);
	myfunc(3,5);
	printf("Value of new name is: %d\n", newname);
	return 0;
}
