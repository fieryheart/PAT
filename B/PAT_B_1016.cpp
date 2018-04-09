#include <iostream>
#include <math.h>

using namespace std;

int main()
{

	long long int A, B, PA=0, PB=0;

	int DA, DB;

	cin >> A >> DA >> B >> DB;

	int num, ca = 0, cb = 0;

	while(A != 0)
	{
		num = A % 10;
		if(num == DA)
			ca++;
		A /= 10;
	}

	while(B != 0)
	{
		num = B % 10;
		if(num == DB)
			cb++;
		B /= 10;
	}

	int i;
	for (i = 0; i < ca; i++)
		PA += DA * pow(10, i);
	for (i = 0; i < cb; i++)
		PB += DB * pow(10, i);

	cout << PA + PB;

	return 0;
}