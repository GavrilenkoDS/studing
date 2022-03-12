#include <stdio.h>
#include <process.h>
#include <math.h>

const float a = 1.00;
const float b = 5.00;

float function(float x){
	return x*x+2*sin(sqrt(x));
}

float trapezoidalIntegral(int n) {
    const float width = (b-a)/n;

    float trapezoidal_integral = 0;
    for(int step = 0; step < n; step++) {
        const float x1 = a + step*width;
        const float x2 = a + (step+1)*width;

        trapezoidal_integral += 0.5*(x2-x1)*(function(x1) + function(x2));
    }

    return trapezoidal_integral;
}

int main(){
	printf("%f\n", trapezoidalIntegral(10));
	printf("%f\n", trapezoidalIntegral(40));
	printf("%f\n", trapezoidalIntegral(160));
	printf("%f\n", trapezoidalIntegral(640));
	
}
