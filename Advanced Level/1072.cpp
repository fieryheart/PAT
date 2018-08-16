#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 9999999;
int n,m,k,ds;
typedef struct Path{
	int id;
	double minn,avg;
}path;
vector<path> vt;
int graph[1050][1050];
void dijkstra(int root)
{
	int id = root - n, i;
	int dis[1050],visit[1050] = {0};
	fill(dis, dis+1050, maxn);
	dis[root] = 0;
	while(true) {
		int v = -1, minn = maxn;
		for(i = 1; i <= n+m; i++)
		{
			if(visit[i] == 0 && dis[i] < minn){
				minn = dis[i];
				v = i;
			}
		}
		if(v == -1) break;
		visit[v] = 1;
		for(int w = 1; w <= n+m; w++)
			if(dis[w] > graph[v][w] + dis[v])
				dis[w] = graph[v][w] + dis[v];
	}
	double minn = 99999999.0, avg = 0.0;
	for(i = 1; i <= n; i++){
		if(dis[i] > ds) return;
		if(dis[i] < minn) minn = dis[i];
		avg += dis[i];
	}
	vt.push_back({id, minn, avg/(n*1.0)});
}
bool cmp(path p, path q)
{
	return p.minn != q.minn ? p.minn > q.minn : (p.avg != q.avg ? p.avg < q.avg : p.id < q.id); 
}
int getv(char p[10], int s)
{
	int v = 0;
	for(int i = s; i < strlen(p); i++)
		v = v*10 + (p[i]-'0');
	return v;
}
int main()
{
	int i,j,d,v,w;
	char p1[10],p2[10];
	cin >> n >> m >> k >> ds;
	fill(graph[0], graph[0]+1050*1050, maxn);
	for(i = 0;i < k; i++)
	{
		scanf("%s %s %d", p1, p2, &d);
		if(p1[0] == 'G') v = getv(p1, 1) + n;	
		else v = getv(p1, 0);
		if(p2[0] == 'G') w = getv(p2, 1) + n;
		else w = getv(p2, 0);
		graph[v][w] = graph[w][v] = d;
	}
	for(i = 1; i <= m; i++)
		dijkstra(n+i);
	sort(vt.begin(), vt.end(), cmp);
	if(vt.size() == 0) cout << "No Solution";
	else printf("G%d\n%.1lf %.1lf", vt[0].id, vt[0].minn, vt[0].avg);
	return 0;
}
