#include <stdio.h>

int main(void){
    int a, b;
    int first, second, third, sum;
    scanf("%d %d", &a,&b);

    first = a * (b%10);
    second = a * ( (b/10)%10) ;
    third = a * ( (b/100)%10) ;
    sum = a*b;
    printf("%d\n", first);
    printf("%d\n", second);
    printf("%d\n", third);
    printf("%d\n", sum);
}