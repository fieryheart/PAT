#include <iostream>
#include <cctype>
using namespace std;
int ascii[127] = {0};
bool pprint[127];
int main()
{
	int i;
	string s1,s2;
	getline(cin, s1);
	for(i = 0; i < s1.length(); i++)
		if(ascii[s1[i]-' '] == 0) ascii[s1[i]-' '] = 1;
	getline(cin, s2);
	for(i = 0; i < s2.length(); i++)
		if(ascii[s2[i]-' '] == 1) ascii[s2[i]-' '] = 2;
	for(i = 0; i < s1.length(); i++){
		int val;
		if(isalpha(s1[i])) val = toupper(s1[i]) - ' ';
		else val = s1[i]-' ';
		if(ascii[s1[i]-' '] == 1 && pprint[val] == false) {
			printf("%c", ' '+val);
			pprint[val] = true;
		}
	}
	return 0;
}
