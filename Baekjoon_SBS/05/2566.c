#include <stdio.h>

int main(void){
    int n_list[9][9];
    int max = -100 , row = 0 , column = 0;
    for(int i = 0 ; i < 9 ; i ++){
        for(int j = 0 ; j < 9 ; j++){
            scanf("%d", &n_list[i][j]);
            if(n_list[i][j] > max){
                row = i+1;
                column = j+1;
                max = n_list[i][j];
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d", row, column);
}

