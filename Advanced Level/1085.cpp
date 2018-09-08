#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, i, p, index = 0, maxn = -1;
	long long value;
	vector<long long> v;
	cin >> n >> p;
	v.resize(n);
	for(i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	sort(v.begin(), v.end());
	for(i = 0; i < n; i++)
	{
		value = v[i] * p;
		while(index < n && v[index] <= value) index++;
		if(index - i > maxn) maxn = index - i;
		if(index == n) break;
	}
	cout << maxn << endl;
	return 0;
}
