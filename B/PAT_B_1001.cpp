#include <iostream>

using namespace std;

int main() 
{
	int num = 0;
	int count = 0;
	cin >> num;

	while (num != 1){

		if ( num % 2 ) { // odd

			num = (3*num + 1) / 2;

		} else { // even

			num = num / 2;

		}

		// cout << num << endl;
		count++;

	}

	// cout << "count : " << count << endl;
	cout << count;

	return 0;
}