#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{

	int i, c;
	int Hest = 0;
	int Lest = 101;
	string s1, s2, s3, Hn, Ln;
	cin >> c;
	getchar();


	for (i = 0; i < c; i++)
	{
		getline(cin,s1);

		int bi = s1.find_last_of(' ');

		s2 = s1.substr(0, bi);
		s3 = s1.substr(bi+1, s1.length()-bi-1);

		int n = atoi(s3.c_str());
		if(n > Hest)
		{
			Hest = n;
			Hn = s2;
		}

		if(n < Lest)
		{
			Lest = n;
			Ln = s2;
		}

	}

	cout << Hn << endl;
	cout << Ln << endl;

	return 0;
}