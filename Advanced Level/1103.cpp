#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> path, tempPath;
int graph[21], n, k, p, maxn = -1;
void dfs(int root, int sum, int nsum)
{
	if(tempPath.size() == k && sum == n) {
		if(nsum > maxn) {
			maxn = nsum;
			path = tempPath;
		}
	}
	if(tempPath.size() < k) {
		for(int i = root; i > 0; i--)
			if(sum + graph[i] <= n){
				tempPath.push_back(i);
				dfs(i, sum+graph[i], nsum+i);	
				tempPath.pop_back();
			}
	}
}
int main()
{
	int i;
	cin >> n >> k >> p;
	for(i = 0; i <= 20; i++)
		graph[i] = pow(i, p);
	dfs(20, 0, 0);
	if(path.size() == 0) {
		printf("Impossible");
		return 0;
	}
	printf("%d = ", n);
	for(i = 0; i < path.size(); i++)
	{
		if(i != 0) printf(" + ");
		printf("%d^%d", path[i], p);
	}
	return 0;
}
