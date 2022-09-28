#include <stdio.h>
#include <string.h>

int main(void){
    int n, count = 0, len;
    char input[101];
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        scanf("%s", input);
        len = strlen(input);
        int flag = 1;
        for(int j = 0 ; j< len ;j++){
            char temp = input[j];
            for(int k = j+2 ; k < len ; k++){
                if(temp == input[k]) flag = 0;
            }
        }
        if (flag) count++;
    }
    printf("%d", count);
}