#include <iostream>
#include <climits>
#include <queue>
using namespace std;
int main()
{
	queue<int> s1,s2;
	int n1, n2, i, cnt = 0, num, ans;
	long long tnum;
	cin >> n1;
	for(i = 0; i < n1; i++)
	{
		scanf("%lld", &tnum);
		num = min((long long)INT_MAX, tnum);
		s1.push(num);
	}
	s1.push(INT_MAX);
	cin >> n2;
	for(i = 0; i < n2; i++)
	{
		scanf("%lld", &tnum);
		num = min((long long)INT_MAX, tnum);
		s2.push(num);
		if(cnt == (n1+n2-1)/2) continue;
		if(s1.front() < s2.front())
			s1.pop();
		else
			s2.pop();
		cnt++;
	}
	s2.push(INT_MAX);
	for(; cnt < (n1+n2-1)/2; cnt++)
		if(s1.front() < s2.front())
			s1.pop();
		else
			s2.pop();
	ans = min(s1.front(), s2.front());
	cout << ans << endl;		
	return 0;
}
