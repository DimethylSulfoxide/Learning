#include <cstdio>

int main(void){
    double a;
    while (~scanf("%lf%*c", &a))
        printf("%.2lf\n", a > 0?a:-a);
    return 0;
}