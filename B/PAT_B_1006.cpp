#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int h;	// hundred
	int t;	// ten
	int o;	// one

	h = n / 100;
	t = n / 10 % 10;
	o = n % 10;

	int i;
	string s = "";

	for (i = 0; i < h; i++)
		s += "B";

	for (i = 0; i < t; i++)
		s += "S";

	for (i = 0; i < o; i++)
		s += ('1' + i);

	cout << s << endl;

	return 0;
}