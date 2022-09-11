#include <stdio.h>

int main(void){
    int n,i,j;
    scanf("%d", &n);
    char temp[n] ;
    for( i = 0 ; i < n ; i++){
        temp[i] = ' ';
    }

    for(j = n-1 ; j >= 0 ; j-- ){
        temp[j] = '*';
        for(i = 0 ; i < n ; i++){
            printf("%c",temp[i]);
        }
        printf("\n");
    }
}