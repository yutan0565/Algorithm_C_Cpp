#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    char board[n][m];
    for(int i = 0 ; i < n ; i++){
         scanf("%s", &board[i]);
    }


    int result = 100;
    for(int i = 0 ; i < n-7 ; i++){
        for(int j = 0 ; j < m-7 ; j++){
            int result_a = 0;
            int result_b = 0;

            for(int a = i ; a < i+8 ; a++){
                for(int b = j ; b < j+8 ; b++){
                    if((a+b)%2 == 0){
                        if(board[a][b] == 'B') result_a++;
                        else result_b++;
                    }else{
                        if(board[a][b] == 'B') result_b++;
                        else result_a++;
                    } 
                }
            }
            if(result > result_a) result = result_a;
            if(result > result_b) result = result_b;
        } 
    }
    printf("%d", result);
    return 0;
}