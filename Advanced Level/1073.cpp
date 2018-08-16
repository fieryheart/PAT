#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int i, point = -1, offset = 0, move = 1;
	string s,rst="", temp = "";
	cin >> s;
	if(s[0] == '-') rst += "-";
	s = s.substr(1);
	for(i = 0; i < s.length(); i++)
	{
		if(point == -1 && s[i] == '.') {
			point = i;
			continue;	
		}
		if(s[i] == 'E') {
			if(s[i+1] == '-') move = 0;
			offset = stoi(s.substr(i+2));
			break;
		}
		temp += s[i];
	}
	if(move == 0) point -= offset;
	else point += offset;
	if(point <= 0) {
		for(i = abs(point); i > 0; i--)
			temp = "0" + temp;
		temp = "0." + temp;
	} else if(point >= temp.length()){
		for(i = temp.length(); i < point; i++)
			temp += "0";
	} else {
		temp = temp.substr(0, point) + "." + temp.substr(point);
	}
	i = 0;
	while(temp[i] == '0' && i+1 < temp.size() && temp[i+1] != '.') temp = temp.substr(1);
	if(temp == "") temp = "0";
	rst += temp;
	cout << rst;
	return 0;
}
