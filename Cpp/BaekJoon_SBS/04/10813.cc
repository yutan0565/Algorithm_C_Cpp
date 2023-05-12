#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SwapValue(vector<int> &num_list, int a,int b)
{   
    swap(num_list[a-1], num_list[b-1]);
//     int temp = num_list[a-1];
//     num_list[a-1] = num_list[b-1];
//     num_list[b-1] = temp;
}

void PrintVector(vector<int> v)
{
    for(int i = 0 ; i < v.size() ; i ++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> num_list;;
    for(int i = 1 ; i < n+1 ; i++) num_list.push_back(i); 
    for(int i = 0 ; i<m ;i++)
    {
        int a,b;
        cin >> a >> b;
        SwapValue(num_list,a,b);
    }
    PrintVector(num_list);
    return 0;
}