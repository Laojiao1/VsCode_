#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define pi 3.1415926535
int main() {
    double n,r;
    scanf("%lf %lf",&n, &r);
    double x = pi * (n-2) / n;
    printf("%.7f\n", r*cos(x/2)/(1-cos(x/2)));
    return 0;
}
