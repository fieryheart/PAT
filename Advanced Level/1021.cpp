#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[10010], temp, deep;
bool visit[10010];
int deepest = -1;
void dfs(int root, int depth)
{
	visit[root] = true;
	if(depth > deepest) {
		deepest = depth;
		temp.clear();
		temp.push_back(root);
	} else if(depth == deepest) {
		temp.push_back(root);
	}
	for(int i = 0; i < graph[root].size(); i++)
		if(visit[graph[root][i]] == false) dfs(graph[root][i], depth+1);
}
int main()
{
	int n, i, cnt = 0, v, w;
	cin >> n;
	for(i = 0; i < n-1; i++)
	{
		scanf("%d%d", &v, &w);
		graph[v].push_back(w);
		graph[w].push_back(v);	
	}
	fill(visit, visit+n+1, false);
	for(i = 1; i <= n; i++)
	{
		if(visit[i] == false) {
			cnt++;
			dfs(i, 1);
		}
	}
	if(cnt > 1) {
		printf("Error: %d components\n", cnt);
	} else {
		deep = temp;
		fill(visit, visit+n+1, false);
		dfs(temp[0], 1);
		for(i = 0; i < temp.size(); i++)
			deep.push_back(temp[i]);
		sort(deep.begin(), deep.end());
		int v = 0;
		for(i = 0; i < deep.size(); i++)
			if(deep[i] != v) {
				v = deep[i];
				cout << v << endl;
			}
	}
	return 0;
}
