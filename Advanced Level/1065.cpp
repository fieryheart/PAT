#include <iostream>
using namespace std;
int main()
{
	int n, i;
	cin >> n;
	long long a, b, c;
	for(i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		long long sum = a+b;
		printf("Case #%d: ", i);
		if(a>0 && b>0 && sum < 0) printf("true\n");
		else if(a < 0 && b < 0 && sum >= 0) printf("false\n");
		else if(sum > c) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
