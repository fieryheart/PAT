#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100010];
int n, cnt, mind = 1000010;
double p, r;
void dfs(int root, int depth)
{
	if(depth > mind) return;
	if(tree[root].size() == 0) {
		if(depth < mind) {
			mind = depth;
			cnt = 1;
		} else if(depth == mind) cnt++;
	}
	for(int i = 0; i < tree[root].size(); ++i)
		dfs(tree[root][i], depth+1);
}
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	for(int i = 0; i < n; ++i)
	{
		int v, w;
		scanf("%d", &v);
		for(int j = 0; j < v; ++j)
		{
			scanf("%d", &w);
			tree[i].push_back(w);
		}
	}
	dfs(0, 0);
	double ans = p * pow(1.0+r/100, mind);
	printf("%.4lf %d", ans, cnt);
	return 0;
}
