#include <stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    int line = 1;
    int sum = 0;
    while(1){
        sum += line;
        if(sum >= x) break;
        line++;
    }
    int up, under;

    if(line%2 == 0){
        up = line - (sum - x);
        under = (line + 1) - up;
        printf("%d/%d", up, under);
    }else{
        under= line - (sum - x);
        up = (line + 1) - under;
        printf("%d/%d", up, under);
    }
    return 0;
}