#include <iostream>
using namespace std;
int main()
{
	int a, b, i, flag = 1;
	cin >> a >> b;
	a += b;
	string s = to_string(a), s1="";
	if(s[0] == '-') {
		flag = 0;
		s = s.substr(1);
	}
	for(i = s.length()-1; i >= 0; i--)
		s1 += s[i];
	s = "";
	for(i = 0; i < s1.length(); i++){
		if(i != 0 && i % 3 == 0) s += ',';
		s += s1[i];
	}
	if(flag == 0) cout << "-";
	for(i = s.length()-1; i>=0; i--)
		cout << s[i];
	return 0;
}
