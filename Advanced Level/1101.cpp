#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, i, maxn = 0;
	vector<int> q, p, ans;
	cin >> n;
	q.resize(n);
	p.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &q[i]);
	p = q;
	sort(p.begin(), p.end());
	for(i = 0; i < n; i++) {
		if(q[i] == p[i] && q[i] > maxn)
			ans.push_back(q[i]);
		if(q[i] > maxn)
			maxn = q[i];	
	}	
	cout << ans.size() << endl;
	for(i = 0; i < ans.size(); i++)
	{
		if(i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
