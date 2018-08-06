#include <iostream>
using namespace std;
int main()
{
	int i,carry = 0, number[10] = {0};
	string s,s1="";
	cin >> s;
	for(i = 0; i < s.length(); i++)
		number[s[i]-'0']++;
	for(i = s.length()-1; i >= 0; i-- )
	{
		s1 = to_string(((s[i]-'0')*2+carry)%10) + s1;
		carry = ((s[i]-'0')*2+carry)/10;
	}
	if(carry != 0) s1 = to_string(carry)+s1;
	for(i = 0; i < s1.length(); i++)
		number[s1[i]-'0']--;
	bool flag = true;
	for(i = 0; i < 10; i++)
		if(number[i] != 0) flag = false;
	if(flag) printf("Yes\n");
	else printf("No\n");
	cout << s1 << endl;
	return 0;
}
