#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   
    int n,m;
    cin >> n >> m;
    vector<int> num_vector;
    for(int i=0 ; i < n ; i++) num_vector.push_back(i+1);
    for(int i=0 ; i < m ; i++)
    {
        int start, end, mid;
        cin >> start >> end >> mid;
        // vector���� ȸ�� ���� ����,  ȸ�� ���� ù��° ��ʼ� interator, interator�� ������
        rotate(num_vector.begin()+start-1, num_vector.begin()+mid-1, num_vector.begin()+end);
    }
    for(int value:num_vector) cout << value << " ";
    cout << endl;
    return 0;
}
