#include <stdio.h>


int isprime(int number){
    if(number == 1) return 0;
    for(int i = 2 ; i*i <= number ; i++){
        if(number%i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        int count = 0;
        for(int i = n+1 ; i <= 2*n ; i++){
            if(isprime(i)) count++;
        }
        printf("%d\n", count);
    }
    return 0 ;
}