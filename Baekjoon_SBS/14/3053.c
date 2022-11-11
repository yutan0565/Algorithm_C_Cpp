#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main(void){
    int r;
    double r_1, r_2;
    
    scanf("%d", &r);
    r_1 = (double)r * r * M_PI;    
    r_2 = (double)r * r * 2;  
    
    printf("%.6lf\n%.6lf", r_1, r_2);
}