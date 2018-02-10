/**
 * carlos gonzález <cgrs@cgrs.me>
 * C progress bars
 * 18 december 2017
 */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

/** macro function to display # by default */
#define default(f) ((strlen(f)>0) ? f[0]: '#')

/**
 * Helper function to get the width of the terminal
 */

int get_width()
{
	// Retrieve terminal dimensions
	struct winsize ws;
	ioctl(0, TIOCGWINSZ, &ws);
	return ws.ws_col;
}

/**
 * Generates a custom progress bar
 */

void print_bar(int percent, char *format) {

	// Format:
	// - 1st character: progress indicator (default: #)
	// - rest of chars: actual percentage indicator
	
	int width = get_width() - 9;
	// 9 = extra characters (numbers, square brackets...)
	
	printf("\r"); // carriage return
	printf("%3d%% [", percent);
	for ( int i = 0; i < percent*width/100 - 1; ++i )
	{
		// display '#' by default if format is empty
		printf("%c", default(format));
	}
	if(strlen(format) > 1)
	{
		// iterate char elements from format 
		// from 1 to n
		printf("%c", format[percent%(strlen(&format[1]))+1]);
	}
	else
	{
		printf("%c", default(format));
	}
	if(percent == 100)
	{
		// Last element printed is a progress indicator
		printf("\b%c", default(format));
	}

	printf("%*c ", (width + 1) - (percent*width/100), ']');
	fflush(stdout);
}

/**
 * Preset bars
 */

void bar_1 (int percent)
{
	print_bar(percent, ""); // Default bar: [#...#]
}

void bar_2 (int percent)
{
	print_bar(percent, "=>"); // [==...=>]
}

void bar_3 (int percent)
{
	print_bar(percent, "#\\|/-"); // spinner-like indicator
}