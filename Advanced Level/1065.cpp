#include <iostream>
using namespace std;
int main()
{
	long long a, b, c, sum;
	int n, i;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		sum = a + b;
		printf("Case #%d: ", i);
		if(a > 0 && b > 0 && sum < 0) printf("true");
		else if(a < 0 && b < 0 && sum >= 0) printf("false");
		else if(sum > c) printf("true");
		else printf("false");	
		printf("\n");	
	} 
	return -0;
}
