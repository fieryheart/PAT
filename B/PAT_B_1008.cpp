#include <iostream>

using namespace std;

int main()
{
	int N,M;
	cin >> N;
	cin >> M;

	int i;
	int arr[5000];
	for(i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int pos = N - M % N;
	for (i = 0; i < N; i++)
	{
		if (i != N-1) cout << arr[(i+pos) % N] << ' ';
		else cout << arr[(i+pos) % N];
	}

	return 0;
}