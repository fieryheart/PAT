#include <iostream>
#include <vector>
using namespace std;
int list[100010][2];
vector<int> v;
int main()
{
	int head, n, k, i, j, temp, val, next;
	cin >> head >> n >> k;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d", &temp, &val, &next);
		list[temp][0] = val;
		list[temp][1] = next;
	}
	temp = head;
	while(temp != -1)
	{
		v.push_back(temp);
		temp = list[temp][1];
	}
	int group = v.size() / k;
	for(i = 0; i < group; i++)
		for(j = 0; j < k/2; j++)
			swap(v[i*k+j], v[i*k+k-1-j]);
	for(i = 0; i < v.size(); i++)
	{
		if(i != v.size()-1) printf("%05d %d %05d\n", v[i], list[v[i]][0], v[i+1]);
		else printf("%05d %d -1", v[i], list[v[i]][0]);
	}
	return 0;
}
