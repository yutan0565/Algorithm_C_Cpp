#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool isTriangle(int a,int b,int c)
{
    int other_sum = 0;
    int max_v = max({a,b,c});
    if(a == max_v)
    {
        if(a < b+c ) return true;
        else return false;
    }
    if(b == max_v)
    {
        if(b < a+c ) return true;
        else return false;
    }
    if(c == max_v)
    {
        if(c < b+a ) return true;
        else return false;
    }
}

int main()
{   
    while(true)
    {
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        int sum = a + b + c;
        if(sum == 0) break;

        if(isTriangle(a,b,c) == false)
        {
            printf("Invalid\n");
            continue;
        }

        if(a == b && b == c && c == a) printf("Equilateral\n");
        else if(a != b && b != c && c != a) printf("Scalene\n");
        else printf("Isosceles\n");
    }
    return 0;
}