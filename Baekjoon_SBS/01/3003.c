#include <stdio.h>

int main(void){
    int ori[6] = {1,1,2,2,2,8};
    int count[6];
    int i;
    for(i=0;i<6;i++){
        int temp;
        scanf("%d",&temp);
        count[i] = temp;
    }

    for(i=0;i<6;i++){
        printf("%d ", ori[i]-count[i]);
    }


}