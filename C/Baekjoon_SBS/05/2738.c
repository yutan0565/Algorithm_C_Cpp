#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[100][100], b[100][100];

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }


    return 0;
}