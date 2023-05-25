#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k; 
    scanf("%d %d", &n, &k);
    int count = 0;
    for(int i = 1 ; i < n+1 ; i++)
    {
        if(n % i == 0) count++;
        if(count == k)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", 0);
    return 0;
}