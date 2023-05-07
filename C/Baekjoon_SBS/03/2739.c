#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);

    int i;
    for(i= 1 ; i < 10 ; i++){
        printf("%d * %d = %d\n", a, i, a*i);
    }
}