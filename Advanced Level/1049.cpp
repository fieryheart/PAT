#include <iostream>
using namespace std;
int main()
{
	int n, left, right, a = 1, ans = 0, now;
	cin >> n;
	while(n / a){
		left = n/(a*10), now = n / a % 10, right = n % a;
		if(now == 0) ans += left*a;
		else if(now == 1) ans += left*a + right + 1;
		else ans += (left+1)*a;
		a = a*10;
	}
	cout << ans;
	return 0;
}
