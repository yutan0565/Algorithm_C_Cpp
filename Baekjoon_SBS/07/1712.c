#include <stdio.h>
#include <string.h>

int main(){
    long a, b ,c ;
    scanf("%ld %ld %ld", &a, &b, &c);

    if(a == 0){
        printf("-1");
        return 0;
    }
    if(b >= c){
        printf("-1");
        return 0;
    }

    int count = a/(c-b) +1;
    printf("%ld", count);

    return 0;
}