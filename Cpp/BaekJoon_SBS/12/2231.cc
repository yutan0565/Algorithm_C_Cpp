#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{   
    int n; scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++)
    {   
        int num = i;
        int sum = i;
        while(num > 0)
        {
            sum += (num%10);
            num /= 10;
        }
        if(sum == n)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", 0);
    return 0;
}