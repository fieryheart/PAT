#include <iostream>
#include <vector>
using namespace std;
int arr[100010] = {0};
int n, m, num;
vector<int> v; 
void getsum(int i, int &j, int &sum)
{
	int left = i, right = n;
	while(left < right) {
		int mid = (left+right) / 2;
		if(arr[mid] - arr[i-1] >= m)
			right = mid;
		else
			left = mid+1;
	}
	j = right;
	sum = arr[j] - arr[i-1];
}
int main()
{
	int i;
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] += arr[i-1];
	}
	int maxn = arr[n];
	for(i = 1; i <= n; i++)
	{
		int j, sum;
		getsum(i, j, sum);
		if(sum > maxn) continue;
		if(sum >= m){
			if(sum < maxn)
			{
				v.clear();
				maxn = sum;
			}
			v.push_back(i);
			v.push_back(j);
		}
	}
	for(i = 0; i < v.size(); i+=2)
		printf("%d-%d\n", v[i], v[i+1]);
	return 0;
}

