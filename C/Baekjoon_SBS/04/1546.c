#include <stdio.h>
int main(void){
    int n;
    int max = 0;
    float avg = 0;

    scanf("%d", &n);

    int score_list[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &score_list[i]);
        if (max < score_list[i]) {
            max = score_list[i];
        }
    }

    for (int i = 0; i < n; i++) {
        avg += (float)score_list[i] / max * 100;
    }

    printf("%f\n", avg / n);
}