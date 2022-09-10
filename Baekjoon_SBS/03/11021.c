#include <stdio.h>

int main(void){
    int n,a,b,i;
    scanf("%d",&n);
    for(i=0; i < n; i++){
        scanf("%d %d\n", &a, &b);
        printf("Case #%d: %d\n", i+1, a+b);
    }
}