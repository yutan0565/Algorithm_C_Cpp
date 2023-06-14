#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

#define MAX_SIZE 1000001
using namespace std;
 
int num_list[MAX_SIZE];
vector<int> result;
int n;
 
void bin_search(int num) {
    int left = 0, right = result.size()-1, mid;
    int idx = INT_MAX;
    while (left <= right) 
    {
        mid = (left + right) / 2;
        int now_num = result[mid];
        if (num <= now_num) 
        {
            if (idx > mid) idx = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    result[idx] = num;
}
 
void make_list() {
    result.push_back(num_list[0]);
    for (int i = 1;i < n;i++) 
    {   
        if (result.back() < num_list[i]) 
        {
            result.push_back(num_list[i]);
        }
        else 
        {
            bin_search(num_list[i]);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> num_list[i];
    } 
    make_list();
 
    cout << result.size();
 
    return 0;
}
