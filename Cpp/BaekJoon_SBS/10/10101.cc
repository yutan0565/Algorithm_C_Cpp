#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b,c; scanf("%d %d %d",&a,&b,&c);
    int sum = a + b + c;

    if(a == b && b == c && c == a && a == 60) printf("Equilateral\n");
    else if(sum == 180)
    {
        if(a != b && b != c && c != a) printf("Scalene\n");
        else printf("Isosceles\n");
    } 
    else printf("Error\n");

    return 0;
}