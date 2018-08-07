#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "#";
	for(int i = 0; i < 3; i++)
	{
		cin >> n;
		if(n == 0) cout << "00";
		else printf("%c%c", n/13 > 9 ? n/13-10+'A' : n/13+'0',  n%13 > 9 ? n%13-10+'A' : n%13+'0');
	}
	return 0;
}
