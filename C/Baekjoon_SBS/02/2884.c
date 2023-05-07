#include <stdio.h>

int main(void){
    int h,m;
    scanf("%d %d", &h, &m);

    int all_min = (h*60 + m - 45) % (60 * 24);

    if (all_min < 0){
        printf("%d %d", 23, 60 + all_min);
    }else{
        int n_h = all_min / 60;
        int n_m = all_min % 60;
        printf("%d %d", n_h, n_m);
    }


}