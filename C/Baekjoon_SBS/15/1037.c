#include <stdio.h>

void swap(int list[], int i, int j){
    int temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void sort(int list[], int n){
    int i, j;
    i = 0;
    while (i < n - 1){
        j = i + 1;
        while (j < n){
            if (list[i] > list[j])
                swap(list, i, j);
            j++;
        }
        i++;
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    int div_list[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &div_list[i]);
    }
    sort(div_list, n);
    int result = div_list[0]*div_list[n-1];

    printf("%d", result);
}