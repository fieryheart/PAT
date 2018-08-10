#include <iostream>
using namespace std;
int number[10010] = {0};
int main()
{
	int n, i, num;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		if(number[num] == 0) number[num] = i;
		else number[num] = -1;
	}
	num = -1;
	int minn = 999999999;
	for(i = 1; i <= 10000; i++)
		if(number[i] > 0 && number[i] < minn) {
			minn = number[i];
			num = i;	
		}
	if(num == -1) cout << "None";
	else cout << num;
	return 0;	
}
