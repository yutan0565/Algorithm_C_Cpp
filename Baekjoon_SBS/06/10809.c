#include <stdio.h>
#include <string.h>

int main(void){
    char input[100];
    scanf("%s", input);

    int len = strlen(input);
    // 97 122

    int result[26] ;
    for(int i = 0 ; i < 26 ; i ++){
        result[i] = -1;
    }
    int flag[26] = {0};


    for(int i = 0 ; i < 26 ; i++){
        char temp = i + 97;
        for(int j = 0 ; j < len ;j++){
            if(input[j] == temp & flag[i] == 0){
                result[i] = j;
                flag[i] = 1;
            }
        }
    }
    
    for(int i = 0 ; i < 26 ; i ++){
        printf("%d ", result[i]);
    }




}