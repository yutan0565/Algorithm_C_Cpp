#include <stdio.h>
#include <string.h>

int main(void){
    char input[16];
    scanf("%s", input);

    int len = strlen(input);
    int result = 0;

    char dial_list[11][5] = {"","","", "ABC", "DEF"
                            , "GHI", "JKL","MNO", "PQRS", "TUV"
                            , "WXYZ"};

    for(int i = 0 ; i < len ; i++){
        char temp = input[i];
        for(int j =0 ; j < 11 ; j++){
            if(strchr(dial_list[j], temp) != NULL){
                result += j;
            }
        }
    }
    printf("%d", result);
}