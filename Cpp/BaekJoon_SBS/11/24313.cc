#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{   
    int a1, a0; scanf("%d %d", &a0, &a1);
    int c,n0; scanf("%d %d", &c, &n0);
    printf("%d\n", ((a1 * n0 + a0 <= c * n0) && (c - a1 >= 0)));
    return 0;
}