#include <iostream>
#include <vector>

using namespace std;
// 没有考虑 M = 1 的情况
int main()
{

	int b, c;

	cin >> b >> c;

	int i,j;
	std::vector<int> v;

	int s = 2;
	int c1 = 0;

	while(c1 < c)
	{

		for (i = 2; i*i <= s; i++)
			if (s % i == 0) break;


		if (s != 2 && s % i == 0) {
			s++;
			continue;
		} else {
			c1++;
		}

		if (c1 >= b)
			v.push_back(s);

		s++;
	}

	int cnt = 0;
	for (i = 0; i < v.size(); i++)
	{
		cnt++;
		if (cnt % 10 != 1) cout << " ";
		cout << v[i];
		if (cnt % 10 == 0) cout << "\n";
	}

	return 0;
}