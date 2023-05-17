#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{   
    vector<int> cut_vector = {3,6,9,12,15,19,22,26};
    vector<int> num_vector = {3,4,5,6,7,8,9,10};

    string input;
    cin >> input;
    int sum = 0;
    for(int i = 0 ; i < input.length() ; i++)
    {
        int index = input[i] - 'A';;
        for(int j= 0 ; j < 8 ; j++)
        {
            if(index < cut_vector[j])
            {   
                sum += num_vector[j];
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}