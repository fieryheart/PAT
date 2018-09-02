#include <iostream>
using namespace std;
int stu[10010] = {0}, checked[10010] = {0};
bool isPrime(int num)
{
	for(int i = 2; i*i <= num; i++ )
		if(num % i == 0) return false;
	return true;
}
int main()
{
	int n, id;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &id);
		stu[id] = i;
	}
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &id);
		if(stu[id] == 0) {
			printf("%04d: Are you kidding?\n", id);
		} else if(checked[id] == 1) {
			printf("%04d: Checked\n", id);
		} else {
			checked[id] = 1;
			if(stu[id] == 1) printf("%04d: Mystery Award\n", id);
			else if(isPrime(stu[id])) {
				printf("%04d: Minion\n", id);
			} else {
				printf("%04d: Chocolate\n", id);
			}
		}
	}
}
