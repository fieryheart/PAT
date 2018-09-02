#include <iostream>
using namespace std;
int main()
{
	int n, i, j, k;
	string s;
	cin >> s >> n;
	for(i = 1; i < n; i++)
	{
		string temp = "";
		for(j = 0; j < s.length(); j = k)
		{
			for(k = j; k < s.length() && s[k] == s[j]; k++);
			temp += to_string((s[j] - '0')*10 + k-j);
		}
		s = temp;
	}
	cout << s;
	return 0;
}
