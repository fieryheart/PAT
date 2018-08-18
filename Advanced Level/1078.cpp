#include <iostream>
using namespace std;
int table[10007] = {0};
bool isPrime(int n)
{
	if(n == 1) return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;
	return true;
}
int findNextPrime(int n)
{
	while(!isPrime(n)) n++;
	return n;
}
int main()
{
	int msize, n, i, num;
	cin >> msize >> n;
	msize = findNextPrime(msize);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		int step = 0;
		for(; step < msize; step++)
			if(table[(num+step*step) % msize] == 0)
			{
				table[(num+step*step) % msize] = num;
				break;
			}
		if(step == msize) printf("-");
		else printf("%d", (num+step*step)%msize);
		if(i != n-1) printf(" ");
	}
	return 0;
}
