#include <stdio.h>

int amin(void){
    int temp[10];
    int i,j, a;
    for(i=0;i<10;i++){
        scanf("%d",&a);
        temp[i] =(a%42);
    }

    int result = 0;
    for(i=0;i<10;i++){
        int count = 0 ;
        for(j=i+1;j<10;j++){
            if(temp[i] == temp[j]){
                count++;
            }
        }
        if(count == 0){
            result++;
        }
    }
}