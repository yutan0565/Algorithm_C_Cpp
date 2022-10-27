#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 1;
    int floor = 0;

    while(1){
        sum += (floor*6);
        floor++;
        if(sum >= n) break;

    }
    printf("%d", floor);
    return 0;
}
