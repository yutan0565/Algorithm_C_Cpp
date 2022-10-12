#include <stdio.h>

int isprime(int n){
    if(n == 1) return 0;
    for(int i = 2 ; i*i <= n ; i ++){
        if(n % i == 0) return 0;
    }
    return 1;
}


int main(){
    int t, number;
    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        scanf("%d", &number);
        int prime_list[number];
        int index = 0; 
        int min = 10001;
        int min_a = 0;
        int min_b = 0;
        for(int j = 2 ; j <= number ; j++){
            if(isprime(j)) prime_list[index++] = j;
        }
        int flag = 0;
        for(int j = 0 ; j < index ; j++){
            int a = prime_list[j];
            for(int k = j ; k < index ; k++){
                int b = prime_list[k];
                if(a+b == number){
                    if((b-a) < min){
                        min_a = a;
                        min_b = b;
                    }

                }
            }
        }
        printf("%d %d\n", min_a, min_b);

    }
    return 0;
}