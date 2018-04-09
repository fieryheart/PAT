#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int p, int q) {
	return p < q;
}

int main()
{

	int n, p;

	cin >> n >> p;

	long long int arr[n];
	int i;

	for(i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr+n, cmp);

	int max = 0, last_j = 0;
	i = 0;
	while( i <= n-1) {
		int j = last_j;
		while( arr[i] * p >= arr[j]) {

			if(j == n)
				break;

			if(j - i + 1 > max)
				max = j - i + 1;

			j++;
			last_j = j;
		}

		if(j == n)
			break;

		i++;
	}

	cout << max;

	return 0;
}