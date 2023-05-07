#include <stdio.h>
#include <string.h>

int main(){
    int a,b,v;
    scanf("%d %d %d", &a, &b, &v);
    int day = 0;

    day = (v - b -1 ) / (a-b) + 1;
    printf("%d", day);



}
