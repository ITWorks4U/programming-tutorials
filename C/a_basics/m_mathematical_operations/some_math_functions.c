/*
* Using mathematical functions, like sine(), cosine(), sinh(), ...
*
* for UNIX systems: The linker needs -lm as additional compiler command,
* otherwise the functions can't be used correctly. This is not required
* everywhere, but you're happier, if you have linked the math libary
* on compile time. ;-)
*/

#include <stdio.h>
#include <stdlib.h>

// for C only
#include <math.h>

// if you prefer to use C++, use this library instead
// #include <cmath>

/*
* Usually, M_PI is not known on a Windows machine, so the application
* is unable to build. Unless, we define M_PI for our own purpose.
*
* NOTE: On some UNIX systems, M_PI is also unknown.
*/
#ifndef M_PI
#define M_PI  3.1415926535897932384626433
#endif

//  customized calculation function
void circle_calculation(void) {
    // area and circumference of a circle
    for(float f = 0.0F; f <= 1.0F; f += 0.1F) {
        float area = M_PI * f * f;
        float circumference = 2 * M_PI * f;

        printf("radius: %f => area: %f, circumference: %f\n", f, area, circumference);
    }
}

void trigonometry(void) {
    // using some math functions from [c]math.h:
    for(double i = 0.0; i <= 90.0; i += 1.0) {
        printf("%2d => {%3.3lf, %3.3lf, %3.3lf, %3.3e, %3.3e, %3.3e}\n", (int) i, sin(i), cos(i), tan(i), sinh(i), cosh(i), tanh(i));
    }
}

void pow_sqrt_log_fmod(void) {
    for(double d = 0.0; d <= 1.0; d += 0.1) {
        printf("%lf => {%3.3e, %3.3e, %3.3e, %3.3e}\n", d, pow(d, d), sqrt(d), log10(d), fmod(d, d));
    }
}

int main(void) {
    circle_calculation();
    trigonometry();
    pow_sqrt_log_fmod();
    return EXIT_SUCCESS;
}