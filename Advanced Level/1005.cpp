#include <iostream>
using namespace std;
string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main()
{
	string s;
	cin >> s;
	int sum = 0;
	for(int i = 0; i < s.length(); i++)
		sum += s[i]-'0';
	s = to_string(sum);
	for(int i = 0; i < s.length(); i++)
	{
		if(i != 0) printf(" ");
		cout << number[s[i]-'0'];
	}
	return 0;
}
