#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point{
    int x;
    int y;
}point;

int compare(const void* first, const void* second){
	point a = *(point*)first;
	point b = *(point*)second;

	if (a.x > b.x)
		return 1;
	else if(a.x == b.x){
		if (a.y > b.y)
			return 1;
		else
			return -1;
	}
	return -1;
}

int main(){
    int n, i;
    scanf("%d", &n);
    point p_list[n];
    for(i = 0 ; i < n ; i++){
        scanf("%d %d", &p_list[i].x, &p_list[i].y);
    }

    qsort(p_list, n, sizeof(point), compare);

	for (i = 0; i < n; i++){
		printf("%d %d\n", p_list[i].x, p_list[i].y);
	}
    return 0;
}