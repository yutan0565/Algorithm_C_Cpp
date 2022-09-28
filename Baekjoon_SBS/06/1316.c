#include <stdio.h>
#include <string.h>

int main()
{
	
	char input[101]; //문자열 배열
	int n ; //input 값 N
	scanf("%d", &n);
	
	int count = n; 
	for (int i = 0; i < n; i++){
		char first = '0';
		int count_list[26] = {0, };
		scanf("%s", input);
		for (int j = 0; j < strlen(input); j++){
			if (first != input[j]){
				first = input[j];
				count_list[input[j]-'a'] += 1;
			}
			if (count_list[input[j] - 'a'] == 2){
				count -= 1;
				break;
			}
		}
	}
	printf("%d", count);
	return 0;
}