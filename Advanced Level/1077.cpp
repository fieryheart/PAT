#include <iostream>
using namespace std;
int main()
{
	string str[110];
	int n,i;
	cin >> n;
	getchar();
	for(i = 0; i < n; i++){
		getline(cin, str[i]);
//		getchar(); 
	}
		
	int findex = str[0].length()-1, lindex = str[1].length()-1;
	string tempS = "";
	while(findex >= 0 && lindex >= 0 && str[0][findex] == str[1][lindex])
	{
		tempS += str[0][findex];
		findex--;
		lindex--;
	}
	for(i = 2; i < n; i++)
	{
		string s = "";
		findex = 0, lindex = str[i].length()-1;
		while(findex < tempS.length() && lindex >= 0 && tempS[findex] == str[i][lindex])
		{
			s += tempS[findex];
			findex++;
			lindex--;
		}
		tempS = s;
	}
	if(tempS == "") cout << "nai";
	else {
		for(i = tempS.size()-1; i >= 0; i--)
			cout << tempS[i];
	}
	return 0;
}
