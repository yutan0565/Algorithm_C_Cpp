#include <stdio.h>

int main(void){
    int max = 0;
    int index ;
    int a;
    int i;
    for(i=1;i<10;i++){
        scanf("%d\n",&a);
        if(a > max){
            max = a;
            index = i;
        }
    }
    printf("%d\n%d",max,index);
}