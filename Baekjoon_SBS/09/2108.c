#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int average(int list[], int n){
    double result;
    double sum;
    for(int i = 0 ; i < n ; i++){
        sum += list[i];
    }  
    result = round(sum/n);
    return (int)result;
}

int middle(int list[], int n){
    if(n == 1) return list[0];
    int result;
    int middle_index = n / 2;
    result = list[middle_index];
    return result;
}

int frequency(int list[], int n){
    int result, max = 0, count = 0, index;
    int count_list[8001] = {0};
    for (int i = 0; i < n; i++){
        index = list[i] + 4000;
        count_list[index]++;
        if(count_list[index] > max) max = count_list[index];
    }

    for(int i = 0, index = 0; i < 8001 ; i++ ){
        if(count_list[i] == 0) continue;
        if(count_list[i] == max){
            if(count == 0){
                index = i;
                count++;
            }else if( count == 1){
                index = i;
                result = index - 4000;
                break;
            }
        }
    }
    return result;
}

int n_range(int list[], int n){
    int result;
	int max = list[n - 1];
	int min = list[0];
	result =  max - min;
    return result;
}

void ft_swap(int list[], int i, int j){
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
                ft_swap(list, i, j);
            j++;
        }
        i++;
    }
}

int main(){
    int n, temp;
    int *n_list;

    scanf("%d", &n);
    n_list = (int*)malloc(sizeof(int) * n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &temp);
        n_list[i] = temp;
    }
    sort(n_list, n);
    printf("%d\n",average(n_list, n) );
    printf("%d\n",middle(n_list, n) );
    printf("%d\n",frequency(n_list, n) );
    printf("%d\n",n_range(n_list, n) );

    free(n_list);

    return 0 ;
}