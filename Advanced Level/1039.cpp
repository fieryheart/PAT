#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stu[27*27*27*10+10];
int getid(char name[5])
{
	int id = 0;
	for(int i = 0; i < 4; i++)
		if(i < 3) id = id*27 + (name[i] - 'A' + 1);
		else id = id*10 + (name[i] - '0');
	return id; 
}
int main()
{
	int q, n, i, j, c, k, id;
	char name[5];
	cin >> q >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &c, &k);
		for(j = 0; j < k; j++)
		{
			scanf("%s", name);
			id = getid(name);
			stu[id].push_back(c);
		}
	}
	for(i = 0; i < q; i++)
	{
		scanf("%s", name);
		id = getid(name);
		sort(stu[id].begin(), stu[id].end());
		printf("%s %d", name, stu[id].size());
		for(j = 0; j < stu[id].size(); j++)
			printf(" %d", stu[id][j]);
		printf("\n");
	}
	return 0;
}
