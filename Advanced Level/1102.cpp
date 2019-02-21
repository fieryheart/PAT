#include <bits/stdc++.h>
using namespace std;
int tree[20][2], visit[20], root = -1;
vector<int> level, in;
void doInverted(int root)
{
	swap(tree[root][0], tree[root][1]);
	if(tree[root][0] != -1) doInverted(tree[root][0]);
	if(tree[root][1] != -1) doInverted(tree[root][1]);
}
void doLevel()
{
	queue<int> q;
//	cout << root << endl;
	q.push(root);
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		level.push_back(v);
		if(tree[v][0] != -1) q.push(tree[v][0]);
		if(tree[v][1] != -1) q.push(tree[v][1]);
	}
}
void doInOrder(int root)
{
	if(tree[root][0] != -1) doInOrder(tree[root][0]);
	in.push_back(root);
	if(tree[root][1] != -1) doInOrder(tree[root][1]);
} 
int main()
{
	int N;
	scanf("%d", &N);
	char c[2];
	for(int i = 0; i < N; ++i)
	{
		cin >> c[0] >> c[1];
		if(c[0] == '-') tree[i][0] = -1;
		else {
			tree[i][0] = c[0]-'0';
			visit[c[0]-'0'] = 1;
		}
		if(c[1] == '-') tree[i][1] = -1;
		else {
			tree[i][1] = c[1]-'0';
			visit[c[1]-'0'] = 1;
		}
	}
	for(int i = 0; i < N; ++i)
		if(!visit[i]) root = i;
	doInverted(root);
	doLevel();
	doInOrder(root);
	for(int i = 0; i < level.size(); ++i)
	{
		if(i != 0) printf(" ");
		printf("%d", level[i]);
	}
	printf("\n");
	for(int i = 0; i < in.size(); ++i)
	{
		if(i != 0) printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");
	return 0;
}
