#include <stdio.h>

int main(void){
    int n, result = 0;
    scanf("%d", &n);
    char number[n];
    scanf("%s", &number);

    for(int i = 0 ; i < n ; i++){
        result += (int)number[i]- 48;
    }
    printf("%d", result);
}