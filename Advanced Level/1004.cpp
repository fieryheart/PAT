#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Tree{
	vector<int> child;
}tree[110];
int level[110] = {0};
int maxDepth = -1;
void dfs(int root, int depth)
{
	if(tree[root].child.size() == 0) {
		level[depth]++;
		if(depth > maxDepth) maxDepth = depth;
	}
	for(int i = 0; i < tree[root].child.size(); i++)
		dfs(tree[root].child[i], depth+1);
}
int main()
{
	int n,m,i,j,node,k,child, maxChild = -1;
	cin >> n >> m;

	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &node, &k);
		for(j = 0; j < k; j++){
			scanf("%d", &child);
			tree[node].child.push_back(child);	
		}
	}
	dfs(1, 1);
	for(i = 1; i <= maxDepth; i++)
	{
		if(i != 1) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
