#include <stdio.h>

int main(void){
    int score_list[30]={ 0,};
    int number;
    for(int i = 0 ; i < 28 ; i++){
        scanf("%d", &number);
        score_list[number-1] = 1;
    }
    for(int i = 0 ; i < 30 ; i++){
        if(score_list[i] == 0) printf("%d\n", i + 1);
    }
}

