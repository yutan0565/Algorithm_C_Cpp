#include <stdio.h>
#include <string.h>
int main(){

    int n_list[10000] = {0, };
    char list_string[10000];
    int temp = 0;
    int i, j;
    scanf("%s", &list_string);

    for (i = 0; i < strlen(list_string); i++){
        n_list[i] = list_string[i] - '0';
    }
    for (i = 0; i < strlen(list_string) - 1; i++){
        for (j = 0; j < strlen(list_string) - 1; j++){
            if (n_list[j] < n_list[j + 1]){
                temp = n_list[j];
                n_list[j] = n_list[j + 1];
                n_list[j + 1] = temp;
            }
        }
    }
    

    for (i = 0; i < strlen(list_string); i++)
        printf("%d", n_list[i]);
    return 0;
}