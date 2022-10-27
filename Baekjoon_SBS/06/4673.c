#include <stdio.h>


int self_number(int n){
    int sum = n;
    while(n>0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}


int main(void){
    int n_list[100001] = {0};
    int result = 0;
    int i;
    for(i = 1; i <10001 ; i++ ){
        result = self_number(i);
        if(result<10001){
            n_list[result] = 1;
        }
    }

    for(i = 1; i <10001 ; i++ ){
        if (n_list[i] != 1){
            printf("%d\n", i);
        }
    }



}