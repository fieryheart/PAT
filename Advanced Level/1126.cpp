#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[510];
int visit[510] = {0}, cnt = 0;
void dfs(int root)
{
	visit[root] = 1;
	cnt++;
	for(int i = 0; i < graph[root].size(); i++)
		if(visit[graph[root][i]] == 0)
			dfs(graph[root][i]);
}
int main()
{
	int n, m, i, v, w, odd = 0, even = 0;
	cin >> n >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		graph[v].push_back(w);
		graph[w].push_back(v);
	}
	dfs(1);
	for(i = 1; i <= n; i++)
		if(graph[i].size() % 2 == 1)
			odd++;
		else
			even++;
	for(i = 1; i <= n; i++)
	{
		if(i != 1) printf(" ");
		printf("%d", graph[i].size());
	}
	printf("\n");
	if(cnt == n && even == n) printf("Eulerian");
	else if(cnt == n && odd == 2) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
