#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    vector<vector<int>> graph;
    vector<int> temp;

    for(int i=0 ; i < 9 ; i++)
    {
        temp.clear();
        for(int j=0 ; j<9 ; j++)
        {
            int x; cin >> x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }
    int max_value = INT_MIN;
    int max_r=-1, max_c=-1;
    for(int i=0 ; i < 9 ; i++)
    {
        for(int j=0 ; j<9 ; j++)
        {
            if(graph[i][j] > max_value)
            {
                max_value = graph[i][j];
                max_r = i+1, max_c = j + 1;
            }
        }
    }
    cout << max_value << endl;
    cout << max_r << " " << max_c << endl;
    return 0;
}