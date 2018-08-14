#include <iostream>
using namespace std;
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int flag = 0;
	for(int i = 0; i < s1.length() && i < s2.length(); i++)
	{
		if(flag == 1 && s1[i] == s2[i] && ((s1[i] >= '0' && s1[i] <= '9') || (s1[i] >= 'A' && s1[i] <= 'N')))
		{
			if(s1[i] >= '0' && s1[i] <= '9') cout << "0" << s1[i] << ":";
			else cout << (s1[i] - 'A') + 10 << ":";
			break;
		}
		if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G')
		{
			cout << week[s1[i] - 'A'] << " ";	
			flag = 1;
		}
	}
	int index = 0;
	for(int i = 0; i < s3.length() && i < s4.length(); i++)
	{
		if(s3[i] == s4[i] && ((s3[i] >= 'a' && s4[i] <= 'z') || (s3[i] >= 'A' && s4[i] <= 'Z')))
		{
			if(index < 10) cout << "0";
			cout << index;
			break;
		}
		else
			index++;
	}
	return 0;
}
