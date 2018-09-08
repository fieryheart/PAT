#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> in,level;
queue<int> q;
int tree[110][3], index = 0;
void inorder(int root)
{
	if(root == -1) return ;
	inorder(tree[root][1]);
	tree[root][0] = in[index++];
	inorder(tree[root][2]);
}
int main()
{
	int n, i;
	cin >> n;
	for(i = 0; i < n; i++)
		scanf("%d%d", &tree[i][1], &tree[i][2]);
	in.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	inorder(0);
	q.push(0);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		level.push_back(tree[v][0]);
		if(tree[v][1] != -1) q.push(tree[v][1]);
		if(tree[v][2] != -1) q.push(tree[v][2]);
	}
	for(i = 0; i < n; i++)
	{
		if(i != 0) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
