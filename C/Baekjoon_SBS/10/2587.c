#include <stdio.h>
#include <stdlib.h>

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
    int n_list[5], sum = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        scanf("%d", &n_list[i]);
        sum += n_list[i];
    }
    sort(n_list, 5);

    int avg = sum/5;
    printf("%d\n%d", avg, n_list[2]);

}