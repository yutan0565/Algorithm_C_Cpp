#include <stdio.h>

int main(void){
    int n,v, count = 0;
    scanf("%d", &n);
    int temp[n];

    for(int i = 0 ; i < n ; i ++){
        scanf("%d", &temp[i]);
    }
    scanf("%d", &v);
    for(int i = 0 ; i < n ; i ++){
        if(temp[i] == v) count++;
    }
    printf("%d", count);

}