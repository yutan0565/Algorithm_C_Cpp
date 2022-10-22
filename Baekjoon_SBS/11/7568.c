#include <stdio.h>

int main(){
    int n,w,h;
    scanf("%d", &n);
    int w_list[51] = {0,};
    int h_list[51] = {0,};

    for(int i = 0 ; i < n ; i++){
        scanf("%d %d", &w_list[i], &h_list[i]);
    }

    for(int i = 0 ; i < n ; i++){
        int upper = 0;
        for(int j = 0; j < n ; j++){
            if(w_list[i] < w_list[j] && h_list[i] < h_list[j]){
                upper++;
            }
        }
        printf("%d ", upper+1);
    }
    return 0;
}