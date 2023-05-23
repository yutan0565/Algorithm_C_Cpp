#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

void getGcdSum(int n)
{
    int sum = 0;

    vector<int> result;
    for(int i=1 ; i < n; i++)
    {
        if(n % i == 0)
        {
            result.push_back(i);
            sum += i;
        }
    }
    if(sum == n)
    {   
        int num_gcd = result.size();
        printf("%d = ", sum);
        for(int i = 0 ; i < num_gcd - 1 ; i++) printf("%d + ", result[i]);
        printf("%d \n", result[num_gcd-1]);
    }
    else
    {
        printf("%d is NOT perfect.\n", n);
    }
}

int main()
{
    while(true)
    {
        int n; 
        scanf("%d", &n);
        if(n == -1) break;
        getGcdSum(n);
    }
    return 0;
}