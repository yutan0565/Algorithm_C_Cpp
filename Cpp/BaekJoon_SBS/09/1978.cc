#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool isPrime(int n)
{   
    if(n == 1) return false;
    for(int i = 2 ; i*i < n + 1; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{   
    int n,cnt = 0;
    scanf("%d", &n);
    for(int i=0; i < n ; i++)
    {
        int num; scanf("%d", &num);
        if(isPrime(num)) cnt += 1;
        else continue;
    }
    printf("%d\n", cnt);
    return 0;
}