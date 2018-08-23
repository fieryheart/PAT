#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int tree[110][3];
int number[110];
queue<int> q;
int t = 0;
void inorder(int root) {
	if(tree[root][1] == -1 && tree[root][2] == -1) {
		tree[root][0] = number[t++];
		return ;
	}
	if(tree[root][1] != -1) inorder(tree[root][1]);
	tree[root][0] = number[t++];
	if(tree[root][2] != -1) inorder(tree[root][2]);
}
void levelorder(int root)
{
	q.push(root);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		if(v != 0) cout << " ";
		cout << tree[v][0];
		if(tree[v][1] != -1) q.push(tree[v][1]);
		if(tree[v][2] != -1) q.push(tree[v][2]);
	}
}
int main()
{
	int n, i, val;
	cin >> n;
	for(i = 0; i < n; i++)
		scanf("%d%d", &tree[i][1], &tree[i][2]);
	for(i = 0; i < n; i++)
		scanf("%d", &number[i]);
	sort(number, number+n);
	inorder(0);
	levelorder(0);
	return 0;
}
