#include <iostream>
using namespace std;
int seq[100010];
int main()
{
	int n, i, index = 0, cnt = 0, ans = 0;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &seq[i]);
		if(seq[i] != i && seq[i] != 0) cnt++;
	}
	while(cnt > 0)
	{
		if(seq[0] == 0) {
			while(index < n) {
				if(seq[index] != index) {
					swap(seq[index], seq[0]);
					ans++;
					break;
				}
				index++;
			}
		}
		while(seq[0] != 0) {
			swap(seq[0], seq[seq[0]]);
			cnt--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
