#include <iostream>
#include <string>

using namespace std;

int main()
{

	int a[10] = {0};

	string s;
	cin >> s;

	int i;
	for(i = 0; i < s.length(); i++)
		a[s[i]-'0'] += 1;

	for(i = 0; i < 10; i++)
		if(a[i] != 0 )
			cout << i << ":" << a[i] << endl;


	return 0;
}