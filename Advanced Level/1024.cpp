#include <iostream>
using namespace std;
bool isPalin(string s)
{
	for(int i = 0; i < s.length()/2; i++)
		if(s[i] != s[s.length()-1-i]) return false;
	return true;
}
string reverse(string s)
{
	string s1 = "";
	for(int i = 0; i < s.length(); i++)
		s1 += s[s.length()-1-i];
	return s1;
}
string addString(string s1, string s2)
{
	int carry = 0;
	string s = "";
	for(int i = 0; i < s1.size(); i++)
	{
		s = s + to_string(((s1[i]-'0')+(s2[i]-'0')+carry)%10);
		carry = ((s1[i]-'0')+(s2[i]-'0')+carry)/10;
	}
	if(carry > 0) s = s + to_string(carry);
	return reverse(s);
}
int main()
{
	string n;
	int k,i;
	cin >> n >> k;
	while(i < k && !isPalin(n)){
		n = addString(n,reverse(n));
		i++;
	}
	cout << n << endl << i << endl; 
	return 0;
}
