#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 99999999;
vector<int> pre[510], tempPath, path;
int bikes[510] = {0}, graph[510][510];
int cmax, sp, n, m, minsend = maxn, minback = maxn;
void dfs(int root)
{
	tempPath.push_back(root);
	if(root == 0) {
		int send = 0, back = 0;
		for(int i = tempPath.size()-1; i >= 0; i--)
		{
			int id = tempPath[i];
			if(bikes[id] >= cmax) back += bikes[id] - cmax;
			else {
				if(back < cmax - bikes[id]) {
					send += cmax - bikes[id] - back;
					back = 0;
				} else back -= cmax - bikes[id];
			}
		}
		if(send < minsend) {
			minsend = send;
			minback = back;
			path = tempPath;
		} else if(send == minsend && back < minback) {
			minback = back;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < pre[root].size(); i++)
		dfs(pre[root][i]);
	tempPath.pop_back();
}
void dijkstra()
{
	int dis[510],visit[510] = {0};
	fill(dis, dis+510, maxn);
	dis[0] = 0;
	while(true) {
		int v = -1, minn = maxn;
		for(int i = 0; i <= n; i++)
		{
			if(visit[i] == 0 && dis[i] < minn)
			{
				v = i;
				minn = dis[i];
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 0; w <= n; w++)
		{
			if(dis[w] > dis[v] + graph[v][w])
			{
				dis[w] = dis[v] + graph[v][w];
				pre[w].clear();
				pre[w].push_back(v);
			} else if(dis[w] == dis[v] + graph[v][w]) {
				pre[w].push_back(v);
			}
		}
	}
	dfs(sp);
	printf("%d ", minsend);
	for(int i = path.size()-1; i >= 0; i--)
	{
		printf("%d", path[i]);
		if(i != 0) printf("->");
	}
	printf(" %d", minback);
}
int main()
{
	int i, v, w, t;
	cin >> cmax >> n >> sp >> m;
	cmax /= 2;
	bikes[0] = cmax;
	for(i = 1; i <= n; i++)
		scanf("%d", &bikes[i]);
	fill(graph[0], graph[0]+510*510, maxn);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v, &w, &t);
		graph[v][w] = graph[w][v] = t;
	}
	dijkstra();
	return 0;
}
