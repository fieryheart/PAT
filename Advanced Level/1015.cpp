#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int x)
{
	if(x == 1) return false;
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) return false;
	return true; 
}
string numToString(int x, int radix)
{
	string s = "";
	while(x != 0)
	{
		s += (x % radix + '0');
		x /= radix;
	}
	return s;
}
string reverseString(string s)
{
	string str = "";
	for(int i = s.length()-1; i >= 0; i--)
		str += s[i];
	return str;
}
int stringToNum(string s, int radix)
{
	int num = 0;
	for(int i = 0; i < s.length(); i++)
		num += (s[i]-'0')*pow(radix, i);
	return num;
}
int main()
{
	int n,d;
	while(cin >> n)
	{
		if(n < 0) break;
		cin >> d;
		if(!isPrime(n) || !isPrime(stringToNum(reverseString(numToString(n, d)), d))) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
