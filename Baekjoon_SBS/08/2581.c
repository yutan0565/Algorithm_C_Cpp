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
    int m, n;
    scanf("%d %d", &m, &n);

    int min_flag = 1, min_prime, sum = 0;
    for(int i = m; i<=n;i++){
        if(i == 1) continue;
        if(isprime(i)){
            sum += i;
            if(min_flag){
                min_prime = i;
                min_flag = 0;
            }
        }
    }

    if(sum == 0) printf("-1");
    else{
        printf("%d\n%d", sum, min_prime);
    }
    return 0;
}