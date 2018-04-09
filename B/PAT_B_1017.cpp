#include <iostream>
#include <string>

using namespace std;

int main()
{

	string s, rst = "";
	int n;
	cin >> s >> n;

	int i, remaind = 0, carry = 0;

	int sl = s.length();
	int ni;
	for (i = 0; i < sl; i++)
	{
		ni = (s[i] - '0') + carry*10;

		if (i+1 < sl) {
			if(ni < n) {
				ni = ni * 10 + s[i+1]-'0';
				rst += "0";
				i++;
			}

			rst += (ni/n + '0');
			carry = ni % n;

			if ( i == sl-1) {
				remaind = carry;
				break;
			}

		} else {
			if(ni < n) {
				remaind = ni % n;
				rst += "0";
				break;
			}
			rst += (ni/n + '0');
			remaind = ni % n;
		}

	}

	while(rst[0] == '0' && rst.length() > 1){
		rst = rst.substr(1, rst.length()-1);
	}

	cout << rst << " " << remaind;
	return 0;
}