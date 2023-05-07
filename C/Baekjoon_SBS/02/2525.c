#include <stdio.h>

int main(void){
    int a,b,c;
    scanf("%d %d\n%d", &a,&b,&c);
    int min_all = a*60+b+c;
    if (min_all >= 60 * 24){
        min_all = min_all % (60 * 24);
    }
    printf("%d %d", min_all/60, min_all%60);


}