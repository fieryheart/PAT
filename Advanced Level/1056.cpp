#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mice[1010] = {0};
vector<int> prem, match;
vector<int> rrank[1010];
int np, ng, index = 0;
bool cmp(int q, int p)
{
	return mice[q] > mice[p];
}
int main()
{
	int i, j;
	cin >> np >> ng;
	for(i = 0; i < np; i++)
		scanf("%d", &mice[i]);
	prem.resize(np);
	for(i = 0; i < np; i++)
		scanf("%d", &prem[i]);
	while(true)
	{
		match.clear();
		for(i = 0; i < prem.size(); i+=ng)
		{
			if(i+ng > prem.size()) sort(prem.begin()+i, prem.end(), cmp);
			else sort(prem.begin()+i, prem.begin()+i+ng, cmp);
			for(j = i; j < i+ng && j < prem.size(); j++)
				if(j == i) match.push_back(prem[j]);
				else rrank[index].push_back(prem[j]);
		}
		index++;
		prem.clear();
		prem = match;
		if(match.size() == 1){
			rrank[index].push_back(match[0]);
			break;
		}
	}
	int t = 1;
	for(i = index; i >= 0; i--)
	{
		for(j = 0; j < rrank[i].size(); j++)
			mice[rrank[i][j]] = t;
		t += rrank[i].size();
	}
	for(i = 0; i < np; i++)
	{
		if(i != 0) printf(" ");
		printf("%d", mice[i]);
	}
	return 0;
}
