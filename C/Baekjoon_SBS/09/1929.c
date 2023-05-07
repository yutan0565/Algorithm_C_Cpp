#include <stdio.h>
#include <math.h>

int isprime(int number){
    if(number == 1) return 0;
    for(int i = 2 ; i*i <= number ; i++){
        if(number%i == 0) return 0;
    }
    return 1;
}

int main(){
    int m, n ;
    scanf("%d %d", &m, &n);
    for(int i = m ; i <= n ; i++){
        if(isprime(i)) printf("%d\n", i);
    }
    return 0;
}