#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int weight[110], n, m, s;
vector<int> tree[110], tempPath;
vector< vector<int> > path;
bool cmp(int q, int p)
{
	return weight[q] > weight[p];
}
void dfs(int root)
{
	tempPath.push_back(root);
	if(tree[root].size() == 0) {
		int ans = 0;
		for(int i = 0; i < tempPath.size(); i++)
			ans += weight[tempPath[i]];
		if(ans == s) path.push_back(tempPath);
	}
	for(int i = 0; i < tree[root].size(); i++)
		dfs(tree[root][i]);
	tempPath.pop_back();
}
int main()
{
	int t, i, j, v, w;
	cin >> n >> m >> s;
	for(i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &t);
		for(j = 0; j < t; j++)
		{
			scanf("%d", &w);
			tree[v].push_back(w);
		}
		sort(tree[v].begin(), tree[v].end(), cmp);
	}
	dfs(0);
	for(i = 0; i < path.size(); i++)
	{
		for(j = 0; j < path[i].size(); j++)
		{
			if(j != 0) printf(" ");
			printf("%d", weight[path[i][j]]);
		}
		printf("\n");
	}
	return 0;
}
