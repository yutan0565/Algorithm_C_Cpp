#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define MAX_CARD 1001
vector<int> card_v(MAX_CARD);
int result = 0;
vector<int> index_v;
vector<vector<int>> combi_group;

vector<vector<int>> makeCombination(int n)
{
    vector<vector<int>> permu_v;
    for(int i = 0 ; i < n-2 ; i++)
    {
        for(int j= i+1 ; j < n-1 ; j++)
        {
            for(int k= j+1 ; k < n ; k++)
            {
                permu_v.push_back({i,j,k});
            }
        }
    }
    return permu_v;
}

int main()
{
    int n,m; scanf("%d %d", &n, &m);
    for(int i=0 ; i < n ; i++) scanf("%d", &card_v[i]);

    int min_gap = INT_MAX;
    int per_size = 3;
    vector<vector<int>> permu_v = makeCombination(n);

    for(int i = 0 ; i < permu_v.size() ; i++)
    {
        int a,b,c; a = permu_v[i][0]; b = permu_v[i][1]; c = permu_v[i][2];
        int sum =  card_v[a] + card_v[b] + card_v[c];
        int gap = abs(sum - m);
        if(gap < min_gap && sum <= m)
        {
            min_gap = gap;
            result = sum;
        }
    }

    printf("%d\n", result);
    return 0;
}