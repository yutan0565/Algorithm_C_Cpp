#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a,b;
    scanf("%d\n %d", &a, &b);
    if( a > 0 && b > 0){
        printf("%d",1);
    }else if( a < 0 && b > 0){
        printf("%d",2);
    }else if( a < 0 && b < 0){
        printf("%d",3);
    }else {
        printf("%d",4);
    }
}