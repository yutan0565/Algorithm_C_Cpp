#include <stdio.h>  

int main() {
    int paper[100][100] = { 0, }; 
    int n, w, h, count = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {  
        scanf("%d %d", &w, &h);
        for (int j = 100 - (h + 10); j < 100 - h; j++) {  
            for (int k = w; k < w + 10; k++) {
                paper[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) { 
        for (int j = 0; j < 100; j++) {  
            if (paper[i][j] == 1) count++;
        }
    }

    printf("%d", count);
    return 0;
}