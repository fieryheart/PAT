#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<string, bool> mapp;
int main()
{
	int n, i, skip, first, cnt=0;
	string s;
	vector<string> v;
	cin >> n >> skip >> first;
	v.resize(n+1);
	for(i = 1; i <= n; i++)
		cin >> v[i];
	for(i = first; i <= n; i += skip)
	{
		while(i <= n && mapp[v[i]] == true) i++;
		if(i <= n) {
			cout << v[i] << endl;
			mapp[v[i]] = true;
			cnt++;
		}
	}
	if(cnt == 0) cout << "Keep going..." << endl;
	return 0;
}
