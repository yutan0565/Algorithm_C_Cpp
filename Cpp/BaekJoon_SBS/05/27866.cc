#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int index;
    cin >> input >> index;
    cout << input[index-1] << endl;
    return 0;
}