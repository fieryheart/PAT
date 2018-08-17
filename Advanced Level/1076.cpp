#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 999999999;
int graph[1010][1010];
int visit[1010] = {0};
int n, l, cnt;
int main()
{
	int i, j, c, v, w;
	cin >> n >> l;
	fill(graph[0], graph[0] + 1010*1010, maxn);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &c);
		for(j = 0; j < c; j++)
		{
			scanf("%d", &w);
			graph[w][i] = 1;
		}
	}
	cin >> c;
	for(i = 0; i < c; i++)
	{
		int last, temp, floor = 0;
		cnt = 0;
		fill(visit+1, visit+n+1, 0);
		queue<int> q;
		scanf("%d", &v);
		q.push(v);
		visit[v] = 1;
		last = v;
		cnt++; 
		while(!q.empty()) {
			w = q.front();
			q.pop();
			for(j = 1; j <= n; j++)
				if(visit[j] == 0 && graph[w][j] == 1) {
					q.push(j);
					visit[j] = 1;
					temp = j;
					cnt++;
				}
			if(w == last) {
				last = temp;
				floor++;
			}
			if(floor > l) break;
		}
		printf("%d\n", cnt-1-q.size());		
	}
	return 0;
}
