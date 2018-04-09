#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int *p, int *q)
{
	int fir = p[1] + p[2];
	int sec = q[1] + q[2];

	if (fir != sec)
	{
		return fir > sec;
	} else if (fir == sec && p[1] != q[1]) {
		return p[1] > q[1];
	} else if (fir == sec && p[1] == q[1]) {
		return p[0] < q[0];
	}
}

int main()
{

	int n, pass, excel;

	cin >> n >> pass >> excel;

	int a[n][3];
	
	// n = 14;
	// pass = 60;
	// excel = 80;

	// int a[14][3] = {
	// 	{10000001, 64, 90},
	// 	{10000002, 90, 60},
	// 	{10000011, 85, 80},
	// 	{10000003, 85, 80},
	// 	{10000004, 80, 85},
	// 	{10000005, 82, 77},
	// 	{10000006, 83, 76},
	// 	{10000007, 90, 78},
	// 	{10000008, 75, 79},
	// 	{10000009, 59, 90},
	// 	{10000010, 88, 45},
	// 	{10000012, 80, 100},
	// 	{10000013, 90, 99},
	// 	{10000014, 66, 60},
	// };


	vector<int*> v[4];

	int i, j;

	// int test[1] = {1};

	// v[0].push_back(test);

	// cout << v[0][0][0] << endl;

	for (i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];

		if (a[i][1] >= excel && a[i][2] >= excel)
			v[0].push_back(a[i]);
		else if (a[i][1] >= excel && a[i][2] >= pass && a[i][2] < excel)
			v[1].push_back(a[i]);
		else if (a[i][1] >= pass && a[i][1] < excel && a[i][2] >= pass && a[i][2] < excel && a[i][1] >= a[i][2])
			v[2].push_back(a[i]);
		else if (a[i][1] >= pass && a[i][1] < excel && a[i][2] >= pass && a[i][1] < a[i][2])
		{
			v[3].push_back(a[i]);
		}	
	}

	int count = 0;
	for (i = 0; i < 4; i++)
		count += v[i].size();


	printf("%d\n", count);

	for (i = 0; i < 4; i++)
	{
		int l = v[i].size();

		sort(v[i].begin(), v[i].end(), cmp);

		for (j = 0; j < l; j++)
			printf("%d %d %d\n", v[i][j][0], v[i][j][1], v[i][j][2]);
	}


	return 0;
}