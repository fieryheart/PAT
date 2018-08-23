#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int tree[25][2];
int isChild[25] = {0};
int main()
{
	string c1,c2;
	int n, i, root;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> c1 >> c2;
		tree[i][0] = c1 == "-" ? -1 : stoi(c1);
		tree[i][1] = c2 == "-" ? -1 : stoi(c2);
		if(tree[i][0] != -1) isChild[tree[i][0]] = 1;
		if(tree[i][1] != -1) isChild[tree[i][1]] = 1;		
	}
	for(i = 0; i < n; i++)
		if(isChild[i] == 0) root = i; 
	queue<int> q;
	int cnt = 0, last;
	q.push(root);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		if(v != -1) {
			last = v;
			cnt++;
		} else {
			if(cnt != n) cout << "NO " << root;
			else cout << "YES " << last;
			return 0;
		}
		q.push(tree[v][0]);
		q.push(tree[v][1]); 
	}
	return 0;
}
