#include <cstdio>
#include <cmath>
#include <math.h>
#define PI 3.1415927

int main(void){
    double r;
    while (~scanf("%lf%*c", &r))
        printf("%.3lf\n", 4.0 / 3 * PI * pow(r, 3));
    return 0;
}