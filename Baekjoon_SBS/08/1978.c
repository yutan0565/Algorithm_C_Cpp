#include <stdio.h>
#include <math.h>

int isprime(int number){
    for(int i = 2 ; i*i <= number; i++){
        if(number % i == 0){
            return 0;         
        }
    }
    return 1;
}


int main(){
    int n;
    int count = 0;
    scanf("%d", &n);
    for(int i = 0 ; i<n ;i++){
        int number;
        scanf("%d", &number);
        if (number == 1) continue;
        if(isprime(number)) count++;
        else continue;
    }
    printf("%d", count);


    return 0;
}