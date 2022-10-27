#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, m, temp;
    scanf("%d %d", &n, &m);
    int *n_list = (int*)malloc(sizeof(int) * n);  
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &temp);
        n_list[i] = temp;
    }

    int max = 0;
    int total;
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = i+1 ; j < n-1 ; j++){
            for(int k = j+1 ; k < n ; k++){
                total = n_list[i] + n_list[j] +n_list[k];
                if( total > m) continue;
                if( total <= m && total > max) max = total;
            }
        }
    }
    printf("%d", max);
    free(n_list);

}

