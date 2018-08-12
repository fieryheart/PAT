#include <iostream>
using namespace std;
int main()
{
	string s1, s2;
	int ascii[200] = {0}, i;
	getline(cin, s1);
	getline(cin, s2);
	for(i = 0; i < s2.length(); i++)
		ascii[s2[i]-' '] = 1;
	for(i = 0; i < s1.length(); i++)
		if(ascii[s1[i]-' '] == 0) cout << s1[i];
	return 0;
}
