#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> candi_v;
int x,y,w,h;

int main()
{
    scanf("%d %d %d %d", &x, &y, &w, &h);
    candi_v.push_back(x);
    candi_v.push_back(w-x);
    candi_v.push_back(y);
    candi_v.push_back(h-y);
    int dis = *min_element(candi_v.begin(), candi_v.end());
    printf("%d\n", dis);
    
    return 0;
}