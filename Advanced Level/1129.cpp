#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<int, int> mapp;
vector<int> v;
bool cmp(int q, int p)
{
	return mapp[q] != mapp[p] ? mapp[q] > mapp[p] : q < p;
}
int main()
{
	int n, i, j, num, k, last = 1;
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(i == 0) {
			v.push_back(num);
			mapp[num]++;
			continue;
		}
		if(mapp[num] + 1 >= last)
			sort(v.begin(), v.end(), cmp);
		printf("%d:", num);
		for(j = 0; j < k && j < v.size(); j++)
			printf(" %d", v[j]);
		last = mapp[v[j-1]];
		printf("\n");
		if(mapp[num] == 0) v.push_back(num);
		mapp[num]++;
	}
	return 0;
}
