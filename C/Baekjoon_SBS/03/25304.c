#include <stdio.h>

int main(void){
    int x, n, a, b;
    scanf("%d\n%d\n", &x, &n);

    int total = 0;
    int i;
    for(i = 0 ; i < n ; i++){
        scanf("%d %d", &a, &b);
        total += (a*b);
    }
    if(total == x){
        printf("%s", "Yes");
    }else{
        printf("%s", "No");
    }

}

