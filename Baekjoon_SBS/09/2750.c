#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int n_list[n];
    int temp;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &n_list[i]);
    }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (n_list[j + 1] < n_list[j]) {
				temp = n_list[j + 1];
				n_list[j + 1] = n_list[j];
				n_list[j] = temp;
			}
		}
	}
    // for(int i = 0 ; i < n ; i++){    
    //     int min = 1001;
    //     int min_index = -1;
    //     for(int j = 0 ; j < n ; j++){
    //         if( min > n_list[j]){
    //             min = n_list[j];
    //             min_index = j;
    //         }
    //     }
    //     result[i] = min;
    //     n_list[min_index] = 10001;
    // }
    for(int i = 0 ; i < n ; i++){
        printf("%d\n", n_list[i]);
    }
    return 0;
}