#include <stdio.h>

int sum(int n){
    int result = 0;
    int i;
    for(i = 1; i < n+1 ; i++){
        result += i;
    }
    return result;
}


int main(void){
    int n;
    scanf("%d", &n);
    int result = sum(n);
    printf("%d\n", result);
}
