#include <stdio.h>

int main(void){
    int a,b;
    scanf("%d %d",&a, &b);
    if(a > b){
        printf("%c",'>');
    }else if(a < b){
        printf("%c",'<');
    }else{
        printf("%s","==");
    }

}