#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string delZero(string s)
{
	while(s[0] == '0') s = s.substr(1);
	return s; 
}
bool cmp(string q, string p)
{
	int len = q.length() > p.length() ? q.length() : p.length();
	for(int i = 0; i < len; i++)
		if(q[i % q.length()] != p[i % p.length()]) return q[i%q.length()] < p[i%p.length()];
	return q.length() > p.length();	
}
int main()
{
	int n,i;
	vector<string> v;
	cin >> n;
	v.resize(n);
	for(i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string r = "";
	for(i = 0; i < n; i++)
		r += v[i];
	if(delZero(r) != "")
		cout << delZero(r);
	else
		cout << "0";  
	return 0;
}
