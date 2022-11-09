#include <stdio.h>
#include <limits.h>

int main(void){
    int x,y,w,h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int min = INT_MAX;

    if(x < min) min = x;
    if(y < min) min = y;
    if(w-x < min) min = w-x;
    if(h-y < min) min = h-y;
    printf("%d", min);
    
}