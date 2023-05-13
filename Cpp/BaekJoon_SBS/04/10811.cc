#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void PrintVector(vector<int> v)
{
    for(int i = 0 ; i < v.size() ; i++) cout << v[i] << " ";
    cout << endl;
}

void ReverseVector(vector<int> &v, int a, int b)
{   
    a -= 1;
    reverse(v.begin()+ a, v.begin() + b);
}

int main()
{
    vector<int> num_vector;
    int n,m ;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) num_vector.push_back(i+1);
    for(int i=0 ; i<m ; i++)
    {
        int a,b;
        cin >> a >> b;
        ReverseVector(num_vector,a,b);
    }
    PrintVector(num_vector);
    return 0;
}