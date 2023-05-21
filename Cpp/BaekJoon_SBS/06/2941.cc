#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> word_vec = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    string str;
    cin >> str;
    int index;
    for(int i = 0; i < word_vec.size(); i++)
    {
        while(true){
            index = str.find(word_vec[i]);
            if(index == string::npos) break;
            str.replace(index,word_vec[i].length(),".");
        }
    }
    cout << str.length();
}