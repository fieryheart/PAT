#include <iostream>
using namespace std;
long long gcd(long long q, long long p)
{
	long long maxn = max(q, p), minn = min(q, p), temp;
	while(maxn % minn != 0) {
		temp = minn;
		minn = maxn % minn;
		maxn = temp;
	}
	return minn;
}
int main()
{
	int n, i;
	long long a, b, c, d, temp;
	cin >> n;
	scanf("%lld/%lld", &a, &b);
	temp = gcd(a, b);
	a /= temp;
	b /= temp;
	for(i = 1; i < n; i++)
	{
		scanf("%lld/%lld", &c, &d);
		temp = gcd(c, d);
		c /= temp;
		d /= temp;
		a = a*d + b*c;
		b = b * d;
		temp = gcd(a, b);
		a /= temp;
		b /= temp;
	}
	long long integer = a/b, frac = a%b;
	if(integer == 0 && frac != 0) printf("%lld/%lld", a, b);
	else if(frac == 0) printf("%lld", integer);
	else printf("%lld %lld/%lld", integer, frac, b);
	return 0;
}
