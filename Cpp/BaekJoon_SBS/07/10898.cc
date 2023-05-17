#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{   
    vector<string> graph;
    string temp;
    int max_len = INT_MIN;
    for(int i=0 ; i < 5 ; i++)
    {
        cin >> temp;
        max_len = max(max_len, int(temp.size()));
        graph.push_back(temp);
    }
    
    int index = 0;
    for(int index = 0 ; index < max_len ; index++)
    {   
        for(int i=0 ; i < 5 ; i++)
        {
            if(index < graph[i].size()) cout << graph[i][index];
        }   
    }
    return 0;
}