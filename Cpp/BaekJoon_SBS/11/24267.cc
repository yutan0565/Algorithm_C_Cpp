#include <iostream>
#include <stdio.h>

typedef long long ll;
using namespace std;

int main()
{
    ll n; scanf("%ld", &n);
    printf("%ld\n%ld\n", n*(n-1)*(n-2)/6,3);
    return 0;
}