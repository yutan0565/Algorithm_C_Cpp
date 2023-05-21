#include <iostream>

#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;

	int step = 1;
	while (n > step) {
		n -= step;
		step++;
	}

	if (step % 2 == 1)
		cout << step + 1 - n << '/' << n << endl;
	else
		cout << n << '/' << step + 1 - n << endl;
}