#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int main(void){
    char input[1000001];
    scanf("%s", input);
 
    int count_list[26];
    for(int i=0; i<26; i++){
        count_list[i]=0;
    }
 
    int len = strlen(input);
    for(int j=0; j<len; j++){
        char cur = toupper(input[j]); 
        count_list[cur-'A']++;
    }
 
    int max = 0, flag = 0, result = 0; 
    for(int k=0; k<26; k++){
        if(count_list[k] > max){
            max = count_list[k];
            flag = 1;
            result='A'+k;
        }
        else if(max!=0 && count_list[k] == max){
            flag++;
        }
        else{
            continue;
        }
    }
 
    if(flag==1){
        printf("%c\n", result);
    }
    else{
        printf("?");
    }
}