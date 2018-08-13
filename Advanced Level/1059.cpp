#include <iostream>
#include <vector>
using namespace std;
bool isPrime(long long num)
{
	if(num == 1) return 0;
	for(long long i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}
long long findNextPrime(long long num)
{
	long long i = 1;
	while(!isPrime(num+i)) i++;
	return num+i;
}
vector<long long> pre;
int main()
{
	long long number,num, cnt = 0, prime = 2, i;
	cin >> num;
	number = num;
	while(num != 1){
		if(num % prime != 0){
			if(cnt != 0) {
				pre.push_back(prime);
				pre.push_back(cnt);
			}
			cnt = 0;
			prime = findNextPrime(prime);
		} else {
			num /= prime;
			cnt++;
		}
	}
	if(cnt != 0) {
		pre.push_back(prime);
		pre.push_back(cnt);
	}
	if(number == 1) {
		printf("1=1");
		return 0;
	}
	printf("%lld=", number);
	for(i = 0; i < pre.size(); i+=2)
	{
		if(i != 0) printf("*");
		printf("%lld", pre[i]);
		if(pre[i+1] > 1) printf("^%lld", pre[i+1]);
	}
	return 0;
}
