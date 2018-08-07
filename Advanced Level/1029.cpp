#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main()
{
	int n, m, i, num,midnum, index = 1;
	long long tnum;
	cin >> n;
	queue<int> q;
	for(i = 0; i < n; i++)
	{
		scanf("%lld", &tnum);
		num = min((long long)INT_MAX, tnum);  
		q.push(num);
	}
	cin >> m;
	int mid = (n+m+1)/2;
	for(i = 0; i < m; i++)
	{
		scanf("%lld", &tnum);
		num = min((long long)INT_MAX, tnum); 
		while(!q.empty() && num > q.front()) {
			if(index == mid) midnum = q.front();
			q.pop();
			index++;
		}
		if(index == mid) midnum = num;
		index++;
	}
	while(index < mid && !q.empty()) {
		q.pop();
		index++;
	}
	if(index == mid) midnum = q.front();
	cout << midnum;
	return 0;
}
