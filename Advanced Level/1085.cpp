#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long long n, p;
	cin >> n >> p;
	vector<long long> v;
	v.resize(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	long long mp, c = 0, maxn = 0, j=0;
	for(int i = 0; i < v.size();i++){
		c = maxn;
		mp = v[i]*p;
		for(j = i+maxn; j < v.size();j++)
			if(v[j] <= mp) c++;
			else break;
		if(c > maxn) maxn = c;
		if(j > v.size()-1) break;
	}
	cout << c;
	return 0;
}
