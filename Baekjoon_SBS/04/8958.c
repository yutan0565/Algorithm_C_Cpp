#include <stdio.h>
#include <string.h>

int main(void){
    int n, i, j,len;
    char s[80];
    scanf("%d", &n);

    int count, sum;
    for(i=0; i < n ; i++){
        scanf("%s",&s);
        len = strlen(s);
        count = 0;
        sum = 0;
        for(j = 0 ; j < len ; j++){
            if(s[j] =='O'){
                count++;
                sum += count;
            }else{
                count = 0;
            }
        }
        printf("%d\n",sum);
    }
}