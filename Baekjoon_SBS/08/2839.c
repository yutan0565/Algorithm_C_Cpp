#include <stdio.h>
 
int main() {
    int n, count = 0;
    scanf("%d", &n);
    
    while (1) {
        if (n % 5 == 0) {
            count += n / 5;
            break;
        }
        n -= 3;
        count++;
        if (n <= 0) break;
    }
 
    if (n < 0) printf("-1\n");
    else printf("%d\n", count);
}