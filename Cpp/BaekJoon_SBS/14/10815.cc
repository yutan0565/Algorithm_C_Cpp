#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_NUM 10000000
using namespace std;
int n,m;
vector<int> num_v(2*MAX_NUM+1, 0);

int main()
{   
    scanf("%d", &n);
    for(int i=0 ; i < n ; i++)
    {
        int a; scanf("%d", &a);
        a += MAX_NUM;
        num_v[a] = 1;
    }
    scanf("%d", &m);
    for(int i=0 ; i < m ; i++)
    {
        int num; scanf("%d", &num);
        num += MAX_NUM;
        printf("%d ", num_v[num]);
    }
    return 0;
}

