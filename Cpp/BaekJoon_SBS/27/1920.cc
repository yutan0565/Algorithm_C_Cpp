#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

vector<int> num_v;
int n,m;

bool bin_search(int left, int right, int num)
{   
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(num_v[mid] == num) return true;
        if(num_v[mid] < num) left = mid +1;
        else right = mid - 1;
    }
    return false;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0 ; i < n ; i++)
    {
        int num; cin >> num;
        num_v.push_back(num);
    }
    sort(num_v.begin(), num_v.end());

    int left=0, right = num_v.size()-1;
    cin >> m;
    for(int i=0 ; i < m ; i++)
    {
        int num; cin >> num;
        if(bin_search(left, right, num)) cout << 1 << endl;
        else cout << 0 << endl;
    }

    
    // cin >> m;
    // for(int i=0 ; i < m ; i++)
    // {
    //     int num; cin >> num;
    //     if(binary_search(num_v.begin(), num_v.end(), num)) cout << 1 << endl;
    //     else cout << 0 << endl;
    // }
    return 0;
}