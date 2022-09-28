#include <stdio.h> 
#include <string.h> 
 
int main(void) { 
    char input[101]; 
    scanf("%s", input); 
    int count = strlen(input); 
    int len = strlen(input); 
    printf("%d\n",count);
    int i; 
    for(i=0; i<len; i++) { 
        if(input[i] == '=') { 
            if(input[i-1] == 'c') count--; 
            if(input[i-1] == 's') count--; 
            if(input[i-1] == 'z') { 
                count--; 
                if(input[i-2] == 'd') count--; 
            } 
        } 
        if(input[i] == '-') { 
            if(input[i-1] == 'c') count--; 
            if(input[i-1] == 'd') count--; 
        } 
        if(input[i] == 'j') { 
            if(input[i-1] == 'l') count--; 
            if(input[i-1] == 'n') count--; 
        } 
    } 
    printf("%d\n", count); 
} 