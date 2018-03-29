#include <iostream>
#include <string>
using namespace std;

int main()
{

	int c;
	cin >> c;

	int i;
	for (i = 0 ; i < c; i++)
	{

		long long int a, b, c;
		cin >> a >> b >> c;

		string s = a + b > c ? "true" : "false";

		cout << "Case #" << i+1 << ": " << s << endl;

	}

	return 0;
}