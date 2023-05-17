#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> correct_vector = { 1,1,2,2,2,8};
    for(int i = 0 ; i < 6 ; i++)
    {
        int x;
        cin >> x;
        cout << correct_vector[i] - x << " ";
    }
    cout << endl;
    return 0;
}