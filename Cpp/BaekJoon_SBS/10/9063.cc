#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX_NODE 100001
using namespace std;

int n;
vector<int> x_v;
vector<int> y_v;

int main()
{   
    scanf("%d", &n);
    for(int i=0 ; i<n ;i++)
    {
        int a,b; scanf("%d %d", &a, &b);
        x_v.push_back(a);
        y_v.push_back(b);
    }

    int x_s = *min_element(x_v.begin(), x_v.end());
    int y_s = *min_element(y_v.begin(), y_v.end());
    int x_e = *max_element(x_v.begin(), x_v.end());
    int y_e = *max_element(y_v.begin(), y_v.end());

    int w,h;
    w = x_e - x_s;
    h = y_e - y_s;
    printf("%d\n", w*h);

    return 0;
}