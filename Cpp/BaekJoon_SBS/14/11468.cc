#include <iostream>
#include <set>

using namespace std;
 
int main() {
    string input_word;
    cin >> input_word;
 
    set<string> word_s;
 
    string str = "";
    for (int i = 0; i < input_word.size(); i++) {
        for (int j = i; j < input_word.size(); j++) {
            str += input_word[j];
            word_s.insert(str);
        }
        str = "";
    }
    cout << word_s.size() << endl;
}
