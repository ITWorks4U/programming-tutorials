/*
* Also reduce the amount of loop states,
* by transform a function runtime from
* O(n) => O(1)
*/

#ifdef __cplusplus
#error "This source code is only for C. By using a C++ compiler your application may be interpreted as a threat."
#else

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>

void print_time(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(fmod(seconds, 3600) / 60);
	double secs = floor(fmod(seconds, 60));

	double fractional = seconds - floor(seconds);
	double milliseconds = floor(fractional * 1000);
	double microseconds = floor(fmod(fractional * 1e6, 1000));
	double nanoseconds  = floor(fmod(fractional * 1e9, 1000));

	fprintf(
		stdout,
		"time amount: %.0lf h, %.0lf min, %.0lf s, %.0lf ms, %.0lf (micro)s, %.0lf ns\n",
		hours, minutes, secs, milliseconds, microseconds, nanoseconds
	);
}

void regular_loop(int upper_boundary) {                 // O(n)
	int summary = 0;

	for(int i = 1; i <= upper_boundary; i++) {
		summary += i;
	}

	printf("summary = %d\n", summary);
}

void fast_loop(int upper_boundary) {                    // O(1)
	printf("summary = %d\n", upper_boundary * (upper_boundary + 1) / 2);
}

int main(void) {
	int upper_boundary = 100;

	clock_t start_timer = clock();
	regular_loop(upper_boundary);
	clock_t end_timer = clock();

	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));

	start_timer = clock();
	fast_loop(upper_boundary);
	end_timer = clock();

	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}

#endif