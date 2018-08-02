#include <iostream>
#include <map>
using namespace std;
map<int, double> mapp1,mapp2,mapp3;
int main()
{
	int n,nk;
	double ni;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%lf", &nk, &ni);
		mapp1[nk] = ni;
	}
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%lf", &nk, &ni);
		mapp2[nk] = ni;
	}
	for(auto it1 = mapp1.begin(); it1 != mapp1.end(); it1++)
	{
		for(auto it2 = mapp2.begin(); it2 != mapp2.end(); it2++)
		{
			mapp3[it1->first+it2->first] += it1->second * it2->second;
		}
	}
	int cnt = 0;
	for(auto it3 = mapp3.begin(); it3 != mapp3.end(); it3++)
		if(it3->second != 0) cnt++;
	cout << cnt;
	for(auto it3 = mapp3.rbegin(); it3 != mapp3.rend(); it3++)
		if(it3->second != 0) printf(" %d %.1lf", it3->first, it3->second);
	return 0;
}
