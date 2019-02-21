#include <bits/stdc++.h>
using namespace std;
int father[1010], hobby[1010], cluster[1010];
int find(int x)
{
	while(x != father[x])
		x = father[x];
	return x;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	father[x] = y;
}
bool cmp(int p, int q)
{
	return p > q;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		father[i] = i;
	for(int i = 1; i <= n; ++i)
	{
		int m, h;
		scanf("%d: ", &m);
		for(int j = 0; j < m; ++j)
		{
			scanf("%d", &h);
			if(hobby[h] == 0) hobby[h] = i;
			else Union(i, hobby[h]);
		}
	}
	for(int i = 1; i <= n; ++i)
		cluster[find(i)]++;
	vector<int> ans;
	for(int i = 1; i <= n; ++i)
		if(cluster[i])
			ans.push_back(cluster[i]);
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); ++i)
	{
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
