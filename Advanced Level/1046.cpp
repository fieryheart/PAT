#include <iostream>
using namespace std;
int seq[100010] = {0};
int main()
{
	int n,  m, i, v, w, dis;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)	
	{
		scanf("%d", &seq[i]);
		seq[i] += seq[i-1];
	}
	cin >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		if(w < v) swap(v, w);
		dis = min(seq[w-1]-seq[v-1], seq[n]-seq[w-1]+seq[v-1]);
		printf("%d\n", dis);
	}
	return 0;
}
