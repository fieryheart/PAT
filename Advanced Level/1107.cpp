#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int isRoot[1010] = {0}, father[1010] = {0}, course[1010] = {0};
int findFather(int node)
{
	int temp = node;
	while(father[node] != node)
		node = father[node];
	father[temp] = node;
	return node;
}
void Union(int nq, int np)
{
	nq = findFather(nq);
	np = findFather(np);
	if(nq != np) father[np] = nq;
}
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	int n,i,v,j,w;
	vector<int> vt;
	cin >> n;
	for(i = 1; i <= n; i++)
		father[i] = i;
	for(i = 1; i <= n; i++)
	{
		scanf("%d: ", &v);
		for(j = 0; j < v; j++)
		{
			scanf("%d", &w);
			if(course[w] == 0) 
				course[w] = i;
			Union(i, course[w]);
		}
	}
	for(i = 1; i <= n; i++)
		isRoot[findFather(i)]++;
	for(i = 1; i <= n; i++)
		if(isRoot[i] != 0)
			vt.push_back(isRoot[i]);
	sort(vt.begin(), vt.end(), cmp);
	cout << vt.size() << endl;
	for(i = 0; i < vt.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", vt[i]);
	}
	return 0;
}
