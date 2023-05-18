#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void putPaper(vector<vector<int>> &graph, int x, int y)
{
    for(int i = x ; i < x+10 ; i++)
    {
        for(int j = y ; j < y+10 ; j++) graph[i][j] = 1;
    }
}

int calPaper(vector<vector<int>> graph)
{
    int result = 0;
    for(int i=0 ; i < 100 ; i++)
    {
        // for(int j=0 ; j < 100 ; j++) result += graph[i][j];
        result += count(graph[i].begin(), graph[i].end(), 1);
    }
    return result;
}

int main()
{   
    vector<vector<int>> graph(100, vector<int>(100, 0));
    int n; cin >> n;
    for(int i=0 ; i < n ; i++)
    {
        int a,b; cin >> a >> b;
        b = 100 - b - 10;
        putPaper(graph,a,b);
    }
    int result = calPaper(graph);
    cout << result << endl;

    return 0;
}