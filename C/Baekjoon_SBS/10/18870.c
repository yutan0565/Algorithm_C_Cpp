#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Point{
	int number;
    int index;
} point;

int compare(const void* first, const void* second) {
	point a = *(point*)first;
	point b = *(point*)second;
	if (a.number > b.number) return 1;
	else if (a.number < b.number) return -1;
	else return 0;
}


int main() {
	int n, i;
	scanf("%d", &n);
	point* n_list = (point*)malloc(sizeof(point) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &n_list[i].number);
		n_list[i].index = i;
	}

	qsort(n_list, n, sizeof(point), compare);

	int* result = (int*)malloc(sizeof(int) * n);
	int count = -1, min = INT_MIN;

	for (i = 0; i < n; i++) {
		if (n_list[i].number != min) {
			min = n_list[i].number;
			count++;
		}
		result[n_list[i].index] = count;
	}
    
	for (i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}

    free(n_list);
    free(result);
}