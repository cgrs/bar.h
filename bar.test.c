#include "bar.h"
#include <stdlib.h>
#include <time.h>

#define RANDSLEEP (50000000 + rand()%100000000)

int main(int argc, char *argv[])
{
	srand((unsigned) time(NULL));

	// 50ms base sleep
	struct timespec ts = {
		.tv_sec = 0,
		.tv_nsec = 50000000
	};

	printf("1st bar:\n");

	for ( int i = 0; i <= 100; ++i )
	{
		ts.tv_nsec = RANDSLEEP;
		bar_1(i);
		nanosleep(&ts, NULL);
	}
	printf("\n");

	printf("2nd bar:\n");
	for ( int i = 0; i <= 100; ++i )
	{
		ts.tv_nsec = RANDSLEEP;
		bar_2(i);
		nanosleep(&ts, NULL);
	}
	printf("\n");

	printf("3rd bar:\n");
	for ( int i = 0; i <= 100; ++i )
	{
		ts.tv_nsec = RANDSLEEP;
		bar_3(i);
		nanosleep(&ts, NULL);
	}
	printf("\n");

	printf("Custom bar:\n");
	for ( int i = 0; i <= 100; ++i )
	{
		ts.tv_nsec = RANDSLEEP;
		print_bar(i, "|)|(");
		nanosleep(&ts, NULL);
	}
	printf("\n");

	return 0;
}