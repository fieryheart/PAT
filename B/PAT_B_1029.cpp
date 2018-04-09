#include <iostream>
#include <string>

using namespace std;

// 将 ascii 码 导入 anki 中背诵

int main()
{

	int ascii[123] = {0}, i;


	string str1, str2;

	cin >> str1 >> str2;

	for(i = 0; i < str2.length(); i++)
		if(ascii[str2[i] - '0' + 48] == 0)
			ascii[str2[i] - '0' + 48] = 1;



	char c;
	for(i = 0; i < str1.length(); i++) {
		
		int asc = str1[i] - '0' + 48;

		if (ascii[asc] == 0) {
			if(asc >= 97 && ascii[asc-32] == 0) {
				c = asc - 32 - 48 + '0';
				cout << c;
				ascii[asc-32] = 1;
			} else if ( asc < 97) {
				c = asc - 48 + '0';
				cout << c;
				ascii[asc] = 1;
			}

		}

	}


	return 0;
}