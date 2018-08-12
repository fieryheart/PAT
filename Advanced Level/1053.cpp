#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< vector<int> > path;
vector<int> tempPath;
struct Tree{
	int w;
	vector<int> child;
}tree[110];
int n, m, s, index = 0;
void dfs(int root, int weight)
{
	tempPath.push_back(root);	
	if(tree[root].child.size() == 0)
	{
		if(weight+tree[root].w == s) {
			path.push_back(tempPath);
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < tree[root].child.size(); i++)
		dfs(tree[root].child[i], weight+tree[root].w);
	tempPath.pop_back();
}
bool cmp(int q, int p)
{
	return tree[q].w > tree[p].w;
}
int main()
{
	int i, j, c, child, root;
	cin >> n >> m >> s;
	for(i = 0; i < n; i++)
		scanf("%d", &tree[i].w);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &root, &c);
		for(j = 0; j < c; j++)
		{
			scanf("%d", &child);
			tree[root].child.push_back(child);
		}
		sort(tree[root].child.begin(), tree[root].child.end(),cmp);
	}
	dfs(0, 0);
	for(i = 0; i < path.size(); i++)
	{
		for(j = 0; j < path[i].size(); j++)
		{
			if(j != 0) printf(" ");
			printf("%d", tree[path[i][j]].w);
		}
		printf("\n");
	}
	return 0;
}
