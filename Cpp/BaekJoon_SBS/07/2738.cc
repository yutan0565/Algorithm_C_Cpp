#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> &graph)
{
    for(int i = 0 ; i < graph.size() ; i++)
    {
        for(int j=0 ; j < graph[1].size() ; j++)
        {
            cout << graph[i][j] << " " ;
        }
        cout << endl;
    }
}


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for(int i = 0 ; i < n ; i++)
    {   
        vector<int> temp;
        for(int j=0 ; j < m ; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        graph.push_back(temp);
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j=0 ; j < m ; j++)
        {
            int x;
            cin >> x;
            graph[i][j] += x;
        }
    }
    print(graph);
    return 0;
}