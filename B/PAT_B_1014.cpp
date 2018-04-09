
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1, s2, s3, s4;

	cin >> s1 >> s2 >> s3 >> s4;

	char t[2];
	int pos;

	// s1 = "3485djDkxh4hhGE";
	// s2 = "2984akDfkkkkggEdsb";
	// s3 = "s&hgsfdk";
	// s4 = "d&Hyscvnm";

	int i = 0;

	while(s1[i] != s2[i] || !(s1[i] >= 'A' && s1[i] <= 'G'))
		i++;

	t[0] = s1[i];

	i++;
	while(s1[i] != s2[i] || !((s1[i] >= 'A' && s1[i] <= 'N') || (s1[i] >= '0' && s1[i] <= '9')))
		i++;

	t[1] = s1[i];


	i = 0;

	while(s3[i] != s4[i] || !((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')))
		i++;

	pos = i;

	string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};

	int m = (t[1] >= '0' && t[1] <= '9') ? t[1] - '0' : t[1] - 'A' + 10;
	cout << week[t[0] - 'A'];

	printf("%02d:%02d", m, pos);

	return 0;
}
