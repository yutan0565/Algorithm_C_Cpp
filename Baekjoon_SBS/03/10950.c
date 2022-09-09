#include <stdio.h>

int main(void){
    int t;
    int a,b;
    scanf("%d", &t);
    int sum[t];
    int i;
    for(i = 0 ; i < t ; i ++){
        scanf("%d %d", &a, &b);
        sum[i] = a+b;
    }
    for(i = 0 ; i < t ; i ++){
        printf("%d\n", sum[i]);
    }
}