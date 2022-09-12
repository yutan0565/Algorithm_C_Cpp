#include <stdio.h>

int main(void){
    int n, count;
    count = 0;
    int a,b,c,d, temp;
    scanf("%d", &n);

    temp = n;

    while(1){
        a = n/10;
        b= n%10;
        c = (a+b) % 10;
        d = (b*10) + c ;
        n = d;
        count++;
        if(d == temp){
            break;
        }
    }
    printf("%d", count);
}