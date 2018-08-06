#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree[10010];
vector<int> deep,temp;
int visit[10010] = {0};
int maxHeight = 0;
void dfs(int root, int height)
{
	visit[root] = 1;
	if(height > maxHeight) {
		temp.clear();
		temp.push_back(root);
		maxHeight = height;
	} else if(height == maxHeight) {
		temp.push_back(root);
	}
	for(int i = 0; i < tree[root].size(); i++)
		if(visit[tree[root][i]] == 0) dfs(tree[root][i], height+1);
	return;
}
int main()
{
	int n,i,v,w;
	cin >> n;
	for(i = 0; i < n-1; i++)
	{
		scanf("%d%d", &v, &w);
		tree[v].push_back(w);
		tree[w].push_back(v);
	}
	int cnt = 0;
	for(i = 1; i <= n; i++)
	{
		if(visit[i] == 0){
			dfs(i,1);
			cnt++;
		}
	} 
	if(cnt > 1) {
		printf("Error: %d components\n", cnt);
	} else {
		int s1 = temp[0];
		deep = temp;
		temp.clear();
		fill(visit, visit+10010, 0);
		dfs(s1, 1);
		for(i = 0; i < temp.size(); i++)
			deep.push_back(temp[i]);
		sort(deep.begin(), deep.end());
		printf("%d\n", deep[0]);
		for(i = 1; i < deep.size(); i++)
			if(deep[i] != deep[i-1])
				printf("%d\n", deep[i]);
	}
	return 0;
}
