#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

	// input
	
	int count;
	cin >> count;

	string s;

	int i;
	for(i = 0; i < count; i++)
	{

		int j;
		int flag1 = 1; 	// besides 'P','A','T'
		int pn = 0;		// 'P' amount
		int tn = 0;		// 'T' amount
		int pi = 0;		// 'P' index
		int ti = 0; 	// 'T' index
		int a_left_n = 0;	// 'A' amount in the left
		int a_center_n = 0; 	// 'A' amount in the center
		int a_right_n = 0; 		// 'A' amount in the right


		cin >> s;

		for (j = 0; j < s.length(); j++)
		{
			if (s[j] != 'P' && s[j] != 'A' && s[j] != 'T')
			{
				flag1 = 0;
				break;
			}

			if(s[j] == 'P') 
				pn++;
			else if(s[j] == 'T')
				tn++;
		}
		if (!flag1 && pn != 1 && tn != 1)
		{
			cout << "NO" << endl;
			continue;
		}


		for (j = 0; j < s.length(); j++)
		{
			if(s[j] == 'P')
				pi = j;
			else if(s[j] == 'T')
				ti = j;
		}


		a_left_n = pi;
		a_center_n = ti - pi - 1;
		a_right_n = s.length() - ti - 1;

		if (a_center_n < 1)
		{
			cout << "NO" << endl;
			continue;
		}

		if (a_left_n * a_center_n == a_right_n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}

	return 0;
}