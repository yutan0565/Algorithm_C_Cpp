#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> str_vector;
    while(true)
    {
        getline(cin,str);
        if(str == "") break;
        str_vector.push_back(str);
    }

    for(int i = 0 ; i < str_vector.size() ; i ++) cout << str_vector[i] << endl;

    return 0;
}