#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int flag[5] = {0,0,0,0,0};
	int A1=0, A2=0, A3=0, A5=0;
	int flag2 = 1, flag4 = 0;
	float A4=0.0;

	int n;
	std::vector<int> v;
	int i;


	int c;
	cin >> c;
	for (i = 0 ; i < c; i++)
	{
		cin >> n;
		v.push_back(n);
	}

	
	for (i = 0; i < v.size(); i++)
		switch (v[i] % 5) {
			case 0:
				if(v[i] % 2 == 0)
				{
					A1 += v[i];
					flag[0] = 1;
				}
				break;
			case 1:
				A2 += flag2 * v[i];
				flag[1] = 1;
				flag2 *= -1;
				break;
			case 2:
				A3++;;
				flag[2] = 1;
				break;
			case 3:
				A4 += v[i];
				flag4++;
				flag[3] = 1;
				break;
			case 4:
				A5 = v[i] > A5 ? v[i] : A5;
				flag[4] = 1;
				break;
		}


	if (flag[0]) cout << A1 << " ";
	else cout << "N ";

	if (flag[1]) cout << A2 << " ";
	else cout << "N ";

	if (flag[2]) cout << A3 << " ";
	else cout << "N ";

	if (flag[3]) printf("%.1f ", A4 / flag4);
	else cout << "N ";

	if (flag[4]) cout << A5;
	else cout << "N";

	return 0;
}