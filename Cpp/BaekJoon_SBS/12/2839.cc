#include <iostream>
#include <stdio.h>

using namespace std;
 
int main() {
    int n, count = 0;
    scanf("%d", &n);
    
    while (true) {
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

    return 0;
}