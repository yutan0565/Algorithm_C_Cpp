#include <stdio.h>

int main(){
    int t, k ,n;
    int total[15][15] = {0,};
    for(int i = 0 ; i < 15 ; i++){
        total[0][i] = i;
    }

    for(int i = 1 ; i < 15 ; i++){
        for(int j = 1 ; j < 15 ; j++){
            total[i][j] =  total[i-1][j] + total[i][j-1];
        }
    }

    scanf("%d", &t);
    for(int i = 0 ; i < t ; i++){
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", total[k][n]);
    }
    return 0;
}