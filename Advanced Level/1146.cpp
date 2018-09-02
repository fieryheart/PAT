#include <iostream>
#include <vector>
using namespace std;
struct Node{
	int in;
	vector<int> out;
}graph[1010];
vector<int> ans;
int count[1010] = {0};
int main()
{
	int n, m, i, j, v, w, k;
	cin >> n >> m;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		graph[v].out.push_back(w);
		graph[w].in++; 
	}
	cin >> k;
	for(i = 0; i < k; i++)
	{
		bool flag = true;
		for(j = 0; j < 1010; j++)
			count[j] = graph[j].in;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &v);
			if(count[v] != 0) flag = false;
			for(w = 0; w < graph[v].out.size(); w++)
				count[graph[v].out[w]]--;
		}
		if(flag == false) ans.push_back(i);
	}
	for(i = 0; i < ans.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	return 0;
}
