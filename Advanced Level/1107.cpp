#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int father[1010], hobby[1010] = {0}, cluster[1010] = {0};
vector<int> v;
int find(int x)
{
	int t = x;
	while(x != father[x])
		x = father[x];
	while(t != x) {
		int temp = father[t];
		father[t] = x;
		t = temp;
	}
	return x;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	father[x] = y;
}
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	int n, i, j, k, h;
	cin >> n;
	for(i = 1; i <= n; i++)
		father[i] = i;
	for(i = 1; i <= n; i++)
	{
		scanf("%d: ", &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &h);
			if(hobby[h] == 0) hobby[h] = i;
			else {
				if(hobby[h] != i) Union(i, hobby[h]);
			}
		}
	}
	for(i = 1; i <= n; i++)
		cluster[find(i)]++;
	for(i = 1; i <= n; i++)
		if(cluster[i] > 0) 
			v.push_back(cluster[i]);
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	for(i = 0; i < v.size(); i++)
		i == 0 ? printf("%d",v[i]) : printf(" %d", v[i]);
	return 0;
}
