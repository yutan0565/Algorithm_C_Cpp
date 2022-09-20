#include <stdio.h>


int check(int n){
    if(n < 100){
        printf("%d", n);
    }else{
        int i, count = 99, a,b,c;
        for(i=100;i<=n;i++){
            a = i/100;
            b = i/10%10;
            c = i%10;
            if((a-b) == (b-c)){
                count++;
            }
        }
        printf("%d", count);

    }

}


int main(void){
    int n;
    scanf("%d", &n);
    check(n);
}