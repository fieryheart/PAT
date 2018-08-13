#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
struct Man{
	char name[10];
	int age, worth;
}man[100010];
int Age[210] = {0};
vector<int> v;
bool cmp(struct Man q, struct Man p)
{
	return q.worth != p.worth ? q.worth > p.worth : (q.age != p.age ? q.age < p.age : strcmp(q.name, p.name) < 0); 
}
int main()
{
	int n, k, m, amin, amax, i, j, t;
	cin >> n >> k;
	for(i = 0; i < n; i++)
		scanf("%s %d %d", &man[i].name, &man[i].age, &man[i].worth);
	sort(man, man+n, cmp);
	for(i = 0; i < n; i++)
		if(Age[man[i].age] < 100){
			v.push_back(i);;
			Age[man[i].age]++;	
		}
	for(i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &m, &amin, &amax);
		vector<int> group;
		for(j = 0; j < v.size(); j++)
			if(man[v[j]].age >= amin && man[v[j]].age <= amax)
				group.push_back(v[j]);
		printf("Case #%d:\n", i);
		if(group.size() == 0) printf("None\n");
		else {
			for(j = 0; j < group.size() && j < m; j++)
				printf("%s %d %d\n", man[group[j]].name, man[group[j]].age, man[group[j]].worth);
		}
	}
	return 0;
}
