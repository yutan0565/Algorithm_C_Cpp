#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);
    if( a >= 90){
        printf("%c", 'A');
    }else if( a >= 80){
        printf("%c", 'B');
    }else if( a >= 70){
        printf("%c", 'C');
    }else if( a >= 60){
        printf("%c", 'D');
    }else{
        printf("%c", 'F');
    }

}