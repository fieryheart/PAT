#include <iostream>

using namespace std;

int main()
{

	int c, i, j;
	int w[3] = {0,0,0};
	int status[2][3] = {0};
	char jia, yi;

	cin >> c;

	for (i = 0; i < c; i++)
	{
		cin >> jia >> yi;

		if(jia == yi) {
			w[1] += 1;
		} else if (jia == 'B' && yi == 'C') {
			w[0] += 1;
			status[0][0] += 1;
		} else if (jia == 'C' && yi == 'B') {
			w[2] += 1;
			status[1][0] += 1;
		} else if (jia == 'C' && yi == 'J') {
			w[0] += 1;
			status[0][1] += 1;
		} else if (jia == 'J' && yi == 'C') {
			w[2] += 1;
			status[1][1] += 1;
		} else if (jia == 'B' && yi == 'J') {
			w[2] += 1;
			status[1][2] += 1;
		} else if (jia == 'J' && yi == 'B') {
			w[0] += 1;
			status[0][2] += 1;
		}
	}

	cout << w[0] << " " << w[1] << " " << w[2] << endl;
	cout << w[2] << " " << w[1] << " " << w[0] << endl;


	for(i = 0; i < 2; i++)
	{
		int pos=-1, max = 0;
		for(j = 0; j < 3; j++)
			if(status[i][j] > max) {
				pos = j;
				max = status[i][j];
			}

		if(pos == 0)
			cout << "B";
		else if (pos == 1)
			cout << "C";
		else if (pos == 2)
			cout << "J";
		else if (pos == -1)		// 错误位置
			cout << "B";

		if(i == 0)
			cout << " ";
	}

	return 0;
}