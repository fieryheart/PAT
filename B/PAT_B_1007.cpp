#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{

	int N;
	cin >> N;

	if(N < 2) return 0;

	int i;
	std::vector<int> v;
	for (i = 2 ; i <= N; i++)
	{

		int flag = 0;
		for (int j = 2; j <= (int)pow(i, 0.5); j++)
		{
			if(!(i % j))
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
			v.push_back(i);

	}

	int count = 0;
	for (i = 0; i < v.size()-1; i++)
		if((v[i+1] - v[i]) == 2)
			count++;

	cout << count <<  endl;
	return 0;
}