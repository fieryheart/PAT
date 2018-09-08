#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Person{
	char name[15];
	int age, worth;
}people[100010];
vector<int> age[210], data;
bool cmp1(struct Person q, struct Person p)
{
	return q.worth != p.worth ? q.worth > p.worth : (q.age != p.age ? q.age < p.age : strcmp(q.name, p.name) < 0);
}
int main()
{
	int n, k, m, i, j, v, w, t;
	cin >> n >> k;
	for(i = 0; i < n; i++)
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
	sort(people, people+n, cmp1);
	for(i = 0; i < n; i++)
		if(age[people[i].age].size() < 100) {
			data.push_back(i);
			age[people[i].age].push_back(i);
		}
	for(i = 1; i <= k; i++) {
		scanf("%d%d%d", &m, &v, &w);
		vector<int> temp;
		for(j = 0; j < data.size(); j++)
			if(people[data[j]].age >= v && people[data[j]].age <= w)
				temp.push_back(data[j]);
		printf("Case #%d:\n", i);
		if(temp.size() == 0) {
			printf("None\n");
			continue;
		}
		for(j = 0; j < temp.size() && j < m; j++)
			printf("%s %d %d\n", people[temp[j]].name, people[temp[j]].age, people[temp[j]].worth);
	}
	return 0;
}
