#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long int a, b, c;
	int scale;
	string s = "";

	cin >> a >> b >> scale;

	c = a + b;

	if (c == 0) { 	// 为考虑 0 的情况
		s = '0';
	}

	while(c != 0)
	{
		s += (c % scale + '0');

		c /= scale;
	}

	// string s1(s.rbegin(), s.rend());
	
	for(int i = s.length()-1; i >= 0; i--)
		cout << s[i];
	// cout << s1;


	return 0;
}