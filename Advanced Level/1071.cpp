#include <iostream>
#include <cctype> 
#include <map>
using namespace std;
map<string, int> mapp;
int main()
{
	string s, sub="", maxstr;
	int maxn = -1;
	getline(cin, s);
	for(int i = 0; i < s.length(); i++)
	{
		if(isdigit(s[i]) || isalpha(s[i]))
			sub += tolower(s[i]);
		else if(sub != ""){
			mapp[sub]++;
			if(mapp[sub] > maxn) {
				maxn = mapp[sub];
				maxstr = sub;
			}
			sub = "";
		}
	}
	if(sub != "") {
		mapp[sub]++;
		if(mapp[sub] > maxn) {
			maxn = mapp[sub];
			maxstr = sub;
		}
		sub = "";		
	}
	cout << maxstr << " " << maxn;
	return 0;
}
