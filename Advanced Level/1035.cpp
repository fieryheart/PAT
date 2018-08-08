#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
map<string, char*> mapp;
vector<string> v;
int main()
{
	int n, i, j;
	cin >> n;
	string name;
	char pass[1010][15];
	for(i = 0;i < n; i++)
	{
		int flag = 0;
		
		cin >> name;
		getchar();
		scanf("%s", pass[i]);
		for(j = 0; j < strlen(pass[i]); j++)
			if(pass[i][j] == '1'){
				pass[i][j] = '@';
				flag = 1;
			} else if(pass[i][j] == '0'){
				pass[i][j] = '%';
				flag = 1;
			} else if(pass[i][j] == 'l'){
				pass[i][j] = 'L';
				flag = 1;
			} else if(pass[i][j] == 'O'){
				pass[i][j] = 'o';
				flag = 1;
			}
		if(flag == 0) continue;
		v.push_back(name);
		mapp[name] = pass[i];
	}
	if(v.size() != 0) {
		cout << v.size() << endl;
		for(i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
			printf("%s\n", mapp[v[i]]);
		}	
	} else {
		if(n == 1) printf("There is %d account and no account is modified", n);
		else printf("There are %d accounts and no account is modified", n);
	}
	return 0;
}
