#include <iostream>
#include <map>
using namespace std;
map<int, int> color;
int main()
{
	int m,n,i,j, c;
	cin >> m >> n;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d", &c);
			color[c]++;
		}
	}
	int maxn = -1, dom;
	map<int, int>::iterator it;
	for(it = color.begin(); it != color.end(); it++)
		if(it->second > maxn){
			maxn = it->second;
			dom = it->first;
		}
	cout << dom;
	return 0;
}
