#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int list[100000][2];
bool cmp(int q, int p)
{
	return list[q][0] < list[p][0];
}
int main()
{
	int n,i,head,temp;
	cin >> n >> head;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		scanf("%d%d", &list[temp][0], &list[temp][1]);
	}
	vector<int> v;
	temp = head;
	while(temp != -1)
	{
		v.push_back(temp);
		temp = list[temp][1];
	}
	if(v.size() == 0) {
		printf("0 -1\n");
		return 0;
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d %05d\n", v.size(), v[0]);
	for(i = 0; i < v.size(); i++)
	{
		if(i == v.size()-1) printf("%05d %d -1\n", v[i], list[v[i]][0]);
		else printf("%05d %d %05d\n", v[i], list[v[i]][0], v[i+1]);
	}
	return 0;
}
