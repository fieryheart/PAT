#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mapp;
map<int, int> pos;
vector<int> in, pre;
void lca(int inL, int inR, int root, int v, int w)
{
	if(inR < inL) return;
	int posr = pos[pre[root]], posv = pos[v], posw = pos[w];
//	printf("posv:%d posr:%d posw: %d\n", posv, posr, posw);
	if(posv < posr && posw > posr || posv > posr && posw < posr)
		printf("LCA of %d and %d is %d.\n", v, w, pre[root]);
	else if(posv < posr && posw < posr)
		lca(inL, posr-1, root+1, v, w);
	else if(posv > posr && posw > posr)
		lca(posr+1, inR, root+1+(posr-inL), v, w);
	else if(posv == posr)
		printf("%d is an ancestor of %d.\n", v, w);
	else if(posw == posr)
		printf("%d is an ancestor of %d.\n", w, v);
}
int main()
{
	int m, n, i, j, root,v, w;
	cin >> m >> n;
	in.resize(n);
	pre.resize(n);
	for(i = 0; i < n; i++){
		scanf("%d", &in[i]);
		mapp[in[i]] = true;
		pos[in[i]] = i;	
	}
	for(i = 0; i < n; i++){
		scanf("%d", &pre[i]);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d%d", &v, &w);
		if(mapp[v] == false && mapp[w] == false) printf("ERROR: %d and %d are not found.\n", v, w);
		else if(mapp[v] == false) printf("ERROR: %d is not found.\n", v);
		else if(mapp[w] == false) printf("ERROR: %d is not found.\n", w);
		else lca(0, n-1, 0, v, w);
	}
	return 0;
}
