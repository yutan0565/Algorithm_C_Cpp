#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c; scanf("%d %d %d", &a,&b,&c);

    int max_v = max({a,b,c});
    int other_sum = 0;
    int result = 0;

    if(a == max_v)
    {
        if(a < b+c ) result = a + b + c;
        else result = 2*(b+c) - 1;
    }
    if(b == max_v)
    {
        if(b < a+c ) result = a + b + c;
        else result = 2*(a+c) - 1;
    }
    if(c == max_v)
    {
        if(c < b+a ) result = a + b + c;
        else result = 2*(b+a) - 1;
    }
    printf("%d\n", result);

    return 0;
}