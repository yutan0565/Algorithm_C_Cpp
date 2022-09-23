#include <stdio.h>
#include <string.h>
int main(void){
    int t, n, i, j,k;
    scanf("%d", &t);
    char input[20];

    for(i=0;i<t;i++){
        scanf("%d %s", &n, input);
        for(j=0;j<strlen(input);j++){
            for(k=0;k<n;k++) printf("%c",input[j]);
        }
        printf("\n");
    }
}