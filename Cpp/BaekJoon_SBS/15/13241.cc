#include <iostream>
#include <stdio.h>

#define endl '\n'
#define ll long long
using namespace std;

ll a,b;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}


int main()
{
    scanf("%ld %ld", &a, &b);
    ll lcm = a * b / gcd(a,b);
    printf("%ld\n", lcm);

    return 0;
}