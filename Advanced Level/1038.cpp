#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(string q, string p)
{
	return q+p < p+q;
}
int main()
{
	int n, i;
	cin >> n;
	v.resize(n);
	for(i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string s = "";
	for(i = 0; i < n; i++)
		s += v[i];
	while(s[0] == '0')	s.erase(s.begin());
	if(s.length() == 0) s = "0";
	cout << s << endl;
	return 0;
}
