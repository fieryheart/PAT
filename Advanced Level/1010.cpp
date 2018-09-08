#include <iostream>
#include <cmath>
using namespace std;
long long getnum(string s, long long radix)
{
	long long num = 0;
	for(int i = s.length()-1; i >= 0; i--)
	{
		if(s[i] > '9') num += (s[i]-'a'+10)*pow(radix, s.length()-1-i);
		else num += (s[i]-'0')*pow(radix, s.length()-1-i);
	
	return num;
}
int main()
{
	string s1, s2, temp;
	long long tag, radix;
	int i;
	cin >> s1 >> s2 >> tag >> radix;
	if(tag == 2) {
		temp = s2;
		s2 = s1;
		s1 = temp;
	}
	char n2c = ' ';
	for(i = 0; i < s2.length(); i++)
		if(s2[i] > n2c) n2c = s2[i];
	long long n2r = n2c > '9' ? n2c-'a'+11 : n2c-'0'+1;
	long long low = n2r, high = max(n2r, getnum(s1, radix)), ans = -1;
	while(low <= high) {
		long long mid = (low + high) / 2;
		if(getnum(s2, mid) < 0 || getnum(s2, mid) > getnum(s1, radix)) high = mid-1;
		else if(getnum(s2, mid) < getnum(s1, radix)) low = mid+1;
		else {
			ans = mid;
			break;
		}
	}
	if(ans == -1) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}
