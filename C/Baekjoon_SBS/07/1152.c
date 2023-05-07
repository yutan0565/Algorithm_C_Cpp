
#include <stdio.h>
#include <string.h>


int main(void){
  
  char input[1000000]; 
  int i,cnt=0,len;

  scanf("%[^\n]",input); 
  len = strlen(input); 

  if (len == 1){   
    if( input[i] == ' '){
      printf("0\n");
      return 0;
    }
  }

  for(i = 1; i<len-1; i++){  
    if( input[i] == ' '){
      cnt++;
    }
  }

  printf("%d", cnt+1); 

  return 0;
}