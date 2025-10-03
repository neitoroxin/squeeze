#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <string.h>

//const double M_PI = acos(-1.0);

double complex polar(double rho, double theta) {
    return rho * (cos(theta) + sin(theta) * I);
}

void _fft(double complex* a, int n, double complex w) {
    if (n <= 1) {
        return;
    }

    int k = (n >> 1);
    _fft(a, k, w * w);
    _fft(a + k, k, w * w);

    double complex wn = 1;
    for (int i = 0; i < k; i++) {
        double complex t = wn * a[i + k];
        a[i + k] = a[i] - t;
		a[i] = a[i] + t;

		wn *= w;
    }
}

void fft(double complex* a, int total_size, int inverse) {
    
}

int main(int argc, char *argv[]) {
    /* complex s = polar(1.0, -2.0);
    printf("%f + %fi\n", creal(s), cimag(s)); */

    char* s = "1011010111010010001110101110111010010001110101110100100100100100100100";
    printf("%s\n", s);
    return 0;
}