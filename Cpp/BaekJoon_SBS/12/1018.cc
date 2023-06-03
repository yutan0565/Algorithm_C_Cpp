#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

#define MAX_N 51
#define MAX_M 51

using namespace std;
char graph[MAX_N][MAX_M];
int n,m;

int main()
{   
    scanf("%d %d", &n, &m);
    for(int i=0 ; i < n ; i++)
    {   
        char str[m];
        scanf("%s", str);
        for(int j=0 ; j < m ; j++)
        {   
            graph[i][j] = str[j];
        }
    }   

    int total_min = INT_MAX;
    for(int a=0 ; a < n-7 ; a++)
    {
        for(int b = 0 ; b < m-7 ;b++)
        {
            // Â¦¼ö °¡ °ËÁ¤
            int count_1 = 0;
            for(int i=a ; i < a+8 ; i++)
            {
                for(int j=b ; j < b+8 ; j++)
                {
                    if((i+j)%2 == 0 && graph[i][j] == 'W') count_1 += 1;
                    else if((i+j)%2 == 1 && graph[i][j] == 'B') count_1 += 1;
                }
            }

            int count_2 = 0;
            for(int i=a ; i < a+8 ; i++)
            {
                for(int j=b ; j < b+8 ; j++)
                {
                    if((i+j)%2 == 0 && graph[i][j] == 'B') count_2 += 1;
                    else if((i+j)%2 == 1 && graph[i][j] == 'W') count_2 += 1;
                }
            }
            int min_v = min(count_1, count_2);
            total_min = min(min_v, total_min);
        }
    }
    printf("%d\n", total_min);
    return 0;
}