#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int score_list[n];
    for(int i = 0; i < n ; i++){
        int score;
        scanf("%d", &score);
        score_list[i] = score;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (score_list[j + 1] < score_list[j]) {
                int temp = score_list[j + 1];
                score_list[j + 1] = score_list[j];
                score_list[j] = temp;
            }
		}
	}
    printf("%d", score_list[n-k]);
    return 0;
}
