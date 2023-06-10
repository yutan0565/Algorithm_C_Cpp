#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define endl '\n'
using namespace std;
int n,m;
map<string, int> name_m;
vector<string> result;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0 ; i < n+m ; i++)
    {
        string name; cin >> name;
        if(name_m.find(name) != name_m.end()) name_m[name] += 1;
        else name_m[name] = 1 ;
    }

    for(auto name : name_m)
    {
        if(name.second == 2) result.push_back(name.first);
    }

    cout << result.size() << endl;
    for(int i=0 ; i < result.size() ; i++) cout << result[i] << endl;
    return 0;
}