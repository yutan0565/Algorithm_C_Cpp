#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, sum;
    int result = 0;
    scanf("%d", &n);
    
    for(int i = 1 ; i <= n ; i++){
        int temp_number =  i;
        result = 0 ;
        sum = i ;
        while(temp_number > 0){
            sum += (temp_number%10);
            temp_number /= 10;
        }
        if(sum == n){
            result = i;
            break;
        }
    }
    printf("%d", result);;

}

