#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

	string str;
	string rst = "";
	int sum = 0;
	std::vector<int> v;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		sum += str[i] - '0';
	}

	if (sum == 0) {

		v.push_back(sum);

	}

	while(sum != 0) {

		v.push_back( sum % 10);
		sum = sum / 10;
	
	}


	for (int i = v.size()-1; i >= 0; i--)
	{
		switch(v[i]) 
		{

			case 0:
					rst += "ling ";
					break;
			case 1:
					rst += "yi ";
					break;
			case 2:
					rst += "er ";
					break;
			case 3:
					rst += "san ";
					break;
			case 4:
					rst += "si ";
					break;
			case 5:
					rst += "wu ";
					break;
			case 6:
					rst += "liu ";
					break;
			case 7:
					rst += "qi ";
					break;
			case 8:
					rst += "ba ";
					break;
			case 9:
					rst += "jiu ";
					break;

		}
	}

	rst.erase(rst.length()-1,1);

	cout << rst;

	return 0;
}