#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
double p, r, product[100010] = {0}, ans=0.0;
vector<int> tree[100010];
void dfs(int root, int depth)
{
	if(tree[root].size() == 0) {
		ans += p * product[root] * pow(1+r/100, depth);
		return;
	}
	for(int i = 0; i < tree[root].size(); i++)
		dfs(tree[root][i], depth+1);
}
int main()
{
	int i, c, j, t;
	cin >> n >> p >> r;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &c);
		if(c == 0) scanf("%lf", &product[i]);
		else {
			for(j = 0; j < c; j++)
			{
				scanf("%d", &t);
				tree[i].push_back(t);
			}
		}
	}
	dfs(0, 0);
	printf("%.1lf", ans);
	return 0;
}
