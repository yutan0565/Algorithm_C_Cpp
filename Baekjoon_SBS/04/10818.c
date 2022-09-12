#include <stdio.h>

int* find_min_max(int list[], int count){
    int min = 1000001;
    int max = -1000001;
    static int result[2] = {0,};
    int i;
    for(i=0 ; i < count; i++){
        if(list[i] > max){
            max = list[i];
        }
        if(list[i] < min){
            min = list[i];
        }
    }
    result[0] = min;
    result[1] = max;

    return result;
}


int main(void){
    int n,a,i;
    int n_list[n];
    scanf("%d", &n);
    for(i = 0 ; i < n ;i++){
        scanf("%d", &a);
        n_list[i] = a;
    }

    int *result= find_min_max(n_list, n);
    printf("%d %d", result[0], result[1]);

}