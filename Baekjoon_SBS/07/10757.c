#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char arr[]) {
	int len = strlen(arr); 
	char temp;
	for (int i = 0; i < len / 2; i++) { 
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;   
	}
}

int main() {
	char a[10002];
	char b[10002];
	char total[10002] = { 0 };
    
	scanf("%s %s", &a, &b);
	reverse(a);
	reverse(b);
	int sum = 0;
	int up=0;

	int len1 = strlen(a);
	int len2 = strlen(b);
	int max = 0;

	if (len1 > len2) max = len1;
	else max = len2;

	for (int i = 0; i < max; i++) {
		sum = a[i] - '0' + b[i] - '0'+up;
		if (sum < 0) sum += '0';
		if (sum >= 10) up = 1;
		else up = 0;
		total[i] = sum % 10 + '0'; 
	}
	if (up == 1) total[max] = '1';
	reverse(total);
	printf("%s", total);
}