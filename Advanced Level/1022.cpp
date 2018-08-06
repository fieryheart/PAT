#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
map< string, vector<int> > title, author, keys, publisher;
vector<int> year[5000];
int main()
{
	int n,m,i,j,id,y;
	string s;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &id);
		getchar();
		
		getline(cin, s);
		title[s].push_back(id);
		getline(cin, s);
		author[s].push_back(id);
		while(cin >> s){
			keys[s].push_back(id);
			char c = getchar();
			if(c == '\n') break;
		}
		getline(cin, s);
		publisher[s].push_back(id);
		scanf("%d", &y);
		year[y].push_back(id);
	}
	cin >> m;
	getchar();
	
	for(i = 0; i < m; i++)
	{
		getline(cin, s);
		string query = s.substr(0,1);
		vector<int> v;
		s = s.substr(3);
		if(query == "1") {
			sort(title[s].begin(), title[s].end());
			v = title[s];		
		} else if(query == "2") {
			sort(author[s].begin(), author[s].end());
			v = author[s];			
		} else if(query == "3") {
			sort(keys[s].begin(), keys[s].end());
			v = keys[s];				
		} else if(query == "4") {
			sort(publisher[s].begin(), publisher[s].end());
			v = publisher[s];			
		} else if(query == "5") {
			sort(year[stoi(s)].begin(), year[stoi(s)].end());
			v = year[stoi(s)];			
		}
		cout << query + ": " + s << endl;
		if(v.size() == 0) printf("Not Found\n");
		else 
			for(j = 0; j < v.size(); j++)
				printf("%07d\n", v[j]);
	}
	return 0;
}
