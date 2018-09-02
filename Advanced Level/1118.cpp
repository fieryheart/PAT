#include <iostream>
using namespace std;
bool alive[10010];
int father[10010], cnt = 0;
int find(int x) 
{
	int temp = x;
	while(x != father[x])
		x = father[x];
	father[temp] = x;
	return x;	
}
void Union(int q, int p)
{
	q = find(q);
	p = find(p);
	if(q != p) father[q] = p;
}
int main()
{
	int n, i, j, k, q, id, first;
	cin >> n;
	for(i = 1; i < 10010; i++)
		father[i] = i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &id);
			if(alive[id] == false) {
				alive[id] = true;
				cnt++;
			}
			if(j == 0) first = id;
			else Union(first, id);
		}
	}
	int root[10010] = {0}, tree = 0;
	for(i = 1;i < 10010; i++)
		if(alive[i] == true)
			root[find(i)]++;
	for(i = 1;i < 10010; i++)
		if(root[i] != 0){
			tree++;
		}
	cout << tree << " " << cnt << endl;
	cin >> q;
	for(i = 0; i < q; i++)
	{
		scanf("%d%d", &j, &k);
		if(find(j) != find(k)) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
