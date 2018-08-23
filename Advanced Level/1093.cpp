#include <iostream>
using namespace std;
int seq[100010][2] = {0};
int main()
{
	string s;
	cin >> s;
	int i;
	seq[0][0] = s[0] == 'P' ? 1 : 0;
	seq[s.length()-1][1] = s[s.length()-1] == 'T' ? 1 : 0;
	for(i = 1; i < s.length(); i++)
		if(s[i] == 'P') seq[i][0] = seq[i-1][0] + 1;
		else seq[i][0] = seq[i-1][0];
	for(i = s.length()-2; i >= 0; i--)
		if(s[i] == 'T') seq[i][1] = seq[i+1][1] + 1;
		else seq[i][1] = seq[i+1][1];
	long long ans = 0;
	for(i = 1; i < s.length()-1; i++)
		if(s[i] == 'A') {
			ans += seq[i][0] * seq[i][1];
			if(ans > 1000000007) ans = ans%1000000007;
		}
	cout << ans;
}
