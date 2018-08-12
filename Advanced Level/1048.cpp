#include <iostream>
using namespace std;
int bag[1010] = {0};
int main()
{
	int n,m,i,num;
	cin >> n >> m;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if(num > m) continue;
		if(bag[m-num] > 0) {
			bag[num] = 2;
			bag[m-num] = 2;
		} else {
			bag[num] = 1;
		}
	}
	for(i = 0; i <= m; i++)
		if(bag[i] == 2) break;
	if(i == m+1) cout << "No Solution";
	else cout << i << " " << m-i;
	return 0;
}
