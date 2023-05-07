#include <stdio.h>

int main(void){
    int t, n, i, j, sum, count;
    float avg;
    scanf("%d",&t);
    for(i=0; i< t;i++){
        sum = 0;
        count = 0;
        avg = 0;
        scanf("%d", &n);
        int temp_score[n];
        for(j=0 ; j<n; j++){
            scanf("%d", &temp_score[j]);
            sum += temp_score[j];
        }
        avg = (float)sum/n;
        for(j=0 ; j<n; j++){
            if(avg < (float)temp_score[j]){
                count++;
            }
        }
        printf("%.3f%%\n",(float)count/n*100);


    }


}