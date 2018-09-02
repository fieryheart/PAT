#include <iostream>
using namespace std;
int table[10007] = {0};
bool isPrime(int x)
{
	if(x == 1) return false;
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) return false;
	return true;
}
int findNextPrime(int x)
{
	while(!isPrime(x)) x++;
	return x;
}
int main()
{
	int msize, n, m, i, step, num, cnt = 0;
	cin >> msize >> n >> m;
	msize = findNextPrime(msize);
	for(i = 0; i < n; i++) {
		scanf("%d", &num);
		for(step = 0; step < msize; step++) {
			if(table[(num+step*step) % msize] == 0) {
				table[(num+step*step) % msize] = num;
				break;
			}
		}
		if(step == msize) printf("%d cannot be inserted.\n", num);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d", &num);
		for(step = 0; step < msize; step++) {
			cnt++;
			if(table[(num+step*step) % msize] == num || table[(num+step*step) % msize] == 0) break;
		}
		if(step == msize) cnt++;
	}
	printf("%.1lf\n", cnt * 1.0 / m);
	return 0;
}
