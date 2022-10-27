#include <stdio.h>
#include <string.h>

void isPalindrome(const char *input, int l, int r,int count){
    if(l >= r){
        printf("%d %d\n", 1, count);
    }else if(input[l] != input[r]){
        printf("%d %d\n", 0, count);
    }else{
        return isPalindrome(input, l+1, r-1, count+1);
    }
}


int main(){
    int n, count;
    scanf("%d", &n);
    char input[1001];
    for(int i = 0 ; i < n;i++){
        scanf("%s", input);
        count = 1;
        isPalindrome(input, 0, strlen(input)-1, count);
    }
}