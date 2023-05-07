#include <stdio.h>

int flag = -1, count = 0 , result = -1;

void merge(int list[], int left, int mid, int right){
	int temp[500001];
	int i = left;       
	int j = mid + 1;   
	int k = 0;          
	while(i <= mid && j <= right){
		if(list[i] <= list[j]) temp[k++] = list[i++];
		temp[k++] = list[j++];
	}
	while(i <= mid) temp[k++] = list[i++];
	while(j <= right) temp[k++] = list[j++];
	k--;
    
	while(k >= 0){
		list[left + k] = temp[k];
		k--;
        count++;
        if(count == k){
            
        }
	}
}

void mergeSort(int list[], int left, int right){
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		mergeSort(list, left, mid);         
		mergeSort(list, mid + 1, right);    
		merge(list, left, mid, right);      
	}
}

int main(void){
	int n_list[500001];
	int n, k;      
	scanf("%d %d", &n, &k);
	for(int i = 0 ; i < n; i++){
		scanf("%d", &n_list[i]);
    }

	mergeSort(n_list, 0, n - 1);   
    for(int i =0 ; i < n ; i++){
        printf("%d ", n_list[i]);
    }
	printf("%d", n_list[k]);

}