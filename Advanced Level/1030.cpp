#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 999999999;
int graph[510][510];
int cost[510][510];
vector<int> pre[510];
vector<int> path, tempPath;
int n,m,s,d,minCost=maxn,minPath=maxn;
void dfs(int root, int ct)
{
	tempPath.push_back(root);
	if(root == s) {
		if(ct < minCost){
			path = tempPath;
			minCost = ct;
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < pre[root].size(); i++)
		dfs(pre[root][i], ct + cost[root][pre[root][i]]);
	tempPath.pop_back();
}
void dijkstra()
{
	int dis[510],visit[510] = {0};
	fill(dis, dis+510, maxn);
	dis[s] = 0;
	while(true)
	{
		int v = -1, minn = maxn;
		for(int i = 0; i < n; i++)
		{
			if(visit[i] == 0 && dis[i] < minn)
			{
				minn = dis[i];
				v = i;
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 0; w < n; w++)
		{
			if(dis[w] > dis[v] + graph[v][w])
			{
				dis[w] = dis[v] + graph[v][w];
				pre[w].clear();
				pre[w].push_back(v);
			} else if(dis[w] == dis[v] + graph[v][w])
			{
				pre[w].push_back(v);
			}
		}
	}
	dfs(d, 0);
	for(int i = path.size()-1; i >= 0; i--)
	{
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[d], minCost);
}
int main()
{
	int i,v,w,dis,c;
	cin >> n >> m >> s >> d;
	fill(graph[0], graph[0]+510*510, maxn);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d%d", &v, &w, &dis, &c);
		graph[v][w] = graph[w][v] = dis;
		cost[v][w] = cost[w][v] = c;
	}
	dijkstra();
	return 0;
}
