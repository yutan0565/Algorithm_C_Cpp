#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string strip(const string& str)
{
    if(str.length() == 0) return str;
    size_t start = str.find_first_not_of(" \n\r\t");
    size_t end = str.find_last_not_of(" \n\r\t");
    if(start == string::npos) return "";
    return string(str, start, end - start + 1);
}

vector<string> split(string str, char deli)
{
    vector<string> result;
    stringstream ss(str);
    string temp;
    while(getline(ss,temp,deli)) result.push_back(temp);
    return result;
}

int main()
{
    vector<string> word_vector;
    string str;
    getline(cin, str);
    str = strip(str);
    word_vector = split(str,' ');
    cout << word_vector.size() << endl;
    return 0;
}