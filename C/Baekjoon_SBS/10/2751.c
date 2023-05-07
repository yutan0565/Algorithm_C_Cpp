#include <stdio.h>

void merge(int list[], int left, int mid, int right){
	int b[1000000];
	int i = left;       
	int j = mid + 1;   
	int k = 0;          
	while(i <= mid && j <= right){
		if(list[i] <= list[j]) b[k++] = list[i++];
		else b[k++] = list[j++];
	}
	while(i <= mid) b[k++] = list[i++];
	while(j <= right) b[k++] = list[j++];
	k--;
    
	while(k >= 0){
		list[left + k] = b[k];
		k--;
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
	int n_list[1000000];
	int n;      
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		scanf("%d", &n_list[i]);
    }
    
	mergeSort(n_list, 0, n - 1);   
	
    for(int i = 0; i < n; i++){
		printf("%d ", n_list[i]);
    }
}