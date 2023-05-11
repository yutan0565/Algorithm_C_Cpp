#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> v)
{
    for(int i=0 ; i < v.size() ; i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{   
    string s;
    cin >> s;
    vector<int> al_vector(26,-1);
    for(int i=0; i < s.length() ; i++)
    {
        int index = (int)s[i] - 'a';
        if(al_vector[index] == -1) al_vector[index] = i;
    }
    printVector(al_vector);
    return 0;
}