#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int n, temp, check, count = 1;
    scanf("%d", &n);
    if (n == 1){
        printf("666");
        return 0;
    }
    
    for (int i = 667;;i++){
        temp = i;
        check = 0;
        while (temp){
            if (temp % 1000 == 666) check = 1;
            temp /= 10;
        }
        if (check){
            count++;
            if (count == n) 
            {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}