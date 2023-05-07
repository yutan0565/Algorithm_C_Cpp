#include <stdio.h>

void make_star(int a, int b , int n){
    if((a/n)%3 == 1 && (b/n)%3==1) printf(" ");
    else{
        if(n/3 == 0) printf("*");
        else make_star(a, b, n/3);
    }
}

int main(void){
    int n, i, j;
    scanf("%d", &n);

    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            make_star(i, j , n);
        }
        printf("\n");
    }
}