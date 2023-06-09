#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

#define endl "\n"
#define MAX_NAME 100001
using namespace std;
int n,m;
map<string,int> name_m;
string num_a[MAX_NAME];

int main()
{
	cin.tie(NULL); cout.tie(NULL);
    scanf("%d %d", &n,&m);
    for(int i=0 ; i < n ; i++)
    {
        string str; cin >> str;
        name_m.insert(make_pair(str, i+1));
        num_a[i+1] = str;
    }

    for(int i=0 ; i < m ; i++)
    {
        string input_info; cin >> input_info;
        if('A' <=input_info[0] && input_info[0] <= 'Z')
        {
            cout << name_m[input_info] << endl;
        }
        else
        {
            int num = stoi(input_info);
            cout << num_a[num] << endl;
        }
    }

    return 0;
}