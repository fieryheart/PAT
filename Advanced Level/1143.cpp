#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> pre;
map<int, bool> mapp; 
int main()
{
	int m, n, v, w, i, j;
	cin >> m >> n;
	for(i = 0; i < n; i++){
		scanf("%d", &v);
		pre.push_back(v);
		mapp[v] = true;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		if(mapp[v] == false && mapp[w] == false) printf("ERROR: %d and %d are not found.\n", v, w);
		else if(mapp[v] == false || mapp[w] == false) printf("ERROR: %d is not found.\n", mapp[v] == false ? v : w);
		else {
			for(j = 0; j < n; j++)
				if((pre[j] < v && pre[j] > w) || (pre[j] > v && pre[j] < w) || pre[j] == v || pre[j] == w) break;
			if(pre[j] == v) printf("%d is an ancestor of %d.\n",v, w);
			else if(pre[j] == w) printf("%d is an ancestor of %d.\n",w, v);
			else printf("LCA of %d and %d is %d.\n", v, w, pre[j]);
		}
	}
	return 0;
}
