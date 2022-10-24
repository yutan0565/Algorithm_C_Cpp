#include <stdio.h>

int main(void){
    int n, temp, check, count = 1, i;
    scanf("%d", &n);
    if (n == 1){
        printf("666");
        return 0;
    }
    
    for (i = 667;; i++){
        temp = i;
        check = 0;
        while (temp){
            if (temp % 1000 == 666) check = 1;
            temp /= 10;
        }
        if (check){
            count++;
            if (count == n) break;
        }
    }
    printf("%d\n", i);
    return 0;
}