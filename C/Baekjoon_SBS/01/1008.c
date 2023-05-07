#include <stdio.h>

int main(){
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%0.9f", (double)a/b);
    return 0;
}