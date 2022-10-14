#include <stdio.h>

int main(){
    int n, number;
    scanf("%d", &n);
    int n_list[n+1] = {0,};
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &number);
        n_list[number]++;
    }


	for (int i = 0; i < 10001; i++) {
		if(n_list[i] == 0) continue;
        for(int j = 0 ; j < n_list[i] ; j++){
            printf("%d\n", i);
        }
	}
    return 0;
}