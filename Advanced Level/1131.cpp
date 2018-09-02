#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 999999999;
int n;
vector<int> graph[10010], path, tempPath;
map<int, int> mapp;
bool visit[10010];
int s, d, minp, mint;
void dfs(int root)
{
	tempPath.push_back(root);
	visit[root] = true;
	if(root == d) {
		int last = tempPath[0], line = mapp[tempPath[0]*10000+tempPath[1]], cnt = 1;
		for(int i = 1; i < tempPath.size(); i++)
		{
			if(mapp[last*10000+tempPath[i]] != line) {
				line = mapp[last*10000+tempPath[i]];
				cnt++;
			}
			last = tempPath[i];
		}
		if(tempPath.size() < minp){
			path = tempPath;
			minp = tempPath.size();
			mint = cnt;
		} else if(tempPath.size() == minp && cnt < mint) {
			path = tempPath;
			mint = cnt;
		}
		tempPath.pop_back();
		visit[root] = false;
		return ;
	}
	for(int i = 0; i < graph[root].size(); i++)
		if(visit[graph[root][i]] == false)
			dfs(graph[root][i]);
	tempPath.pop_back();
	visit[root] = false;
}
int main()
{
	int i, j, k, last, v, w, q;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &v);
			if(j == 0) last = v;
			else {
				mapp[last*10000+v] = mapp[v*10000+last] = i;
				graph[last].push_back(v);
				graph[v].push_back(last);
				last = v;
			}
		}
	}
	scanf("%d", &q);
	for(i = 0; i < q; i++)
	{
		scanf("%d%d", &s, &d);
		fill(visit, visit+10010, false);
		minp = maxn;
		mint = maxn;
		path.clear();
		tempPath.clear();
		dfs(s);
		int line = mapp[path[0]*10000+path[1]], start = path[0], last = path[0];
		printf("%d\n", path.size()-1);
		for(j = 1; j < path.size(); j++)
		{
			if(mapp[last*10000+path[j]] != line) {
				printf("Take Line#%d from %04d to %04d.\n", line, start, last);
				line = mapp[last*10000+path[j]];
				start = last;
			}
			last = path[j];
		}
		printf("Take Line#%d from %04d to %04d.\n", line, start, last);
	}
	return 0;
}
