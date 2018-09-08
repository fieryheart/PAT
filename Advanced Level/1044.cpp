#include <iostream>
#include <vector>
using namespace std;
int seq[100010] = {0}, n, m;
vector<int> v;
void match(int i, int &j, int &sum)
{
	int left = i, right = n;
	while(left < right)
	{
		int mid = (left+right)/2;
		if(seq[mid] - seq[i-1] >= m) right = mid;
		else left = mid+1;
	}
	j = right;
	sum = seq[right] - seq[i-1];
}
int main()
{
	int i;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &seq[i]);
		seq[i] += seq[i-1];
	}
	int maxn = seq[n];
	for(i = 1; i <= n; i++)
	{
		int j, sum;
		match(i, j, sum);
		if(sum > maxn) continue;
		if(sum >= m) {
			if(sum < maxn) {
				maxn = sum;
				v.clear();
			}
			v.push_back(i);
			v.push_back(j);
		}
	}
	for(i = 0; i < v.size(); i+=2)
		printf("%d-%d\n", v[i], v[i+1]);
	return 0;
}
