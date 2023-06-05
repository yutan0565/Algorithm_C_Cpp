#include <iostream>
#include <vector>
#include <stdio.h>

#define endl '\n'
#define MAX_NUM 10000000
using namespace std;

int n,m;
vector<int> num_v(MAX_NUM*2+1, 0);

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0 ; i < n ; i++)
    {
        int num; cin >> num;
        num += MAX_NUM;
        num_v[num] += 1;
    }
    cin >> m;
    for(int i=0 ; i < m ; i++)
    {
        int num; cin >> num;
        num += MAX_NUM;
        cout << num_v[num] << " ";
    }
    cout << endl;

    return 0;
}