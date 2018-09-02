#include <iostream>
#include <algorithm>
using namespace std;
int tree[1010], m, n;
bool isMaxHeap(int root) {
	if(root >= n) return true;
	if((root*2+1 < n && tree[root*2+1] > tree[root]) || 
		(root*2+2 < n && tree[root*2+2] > tree[root])) return false;
	return isMaxHeap(root*2+1) && isMaxHeap(root*2+2);
}
bool isMinHeap(int root) {
	if(root >= n) return true;
	if((root*2+1 < n && tree[root*2+1] < tree[root]) || 
		(root*2+2 < n && tree[root*2+2] < tree[root])) return false;
	return isMinHeap(root*2+1) && isMinHeap(root*2+2);
}
void postOrder(int root) {
	if(root >= n) return;
	postOrder(root*2+1);
	postOrder(root*2+2);
	printf("%d", tree[root]);
	if(root != 0) printf(" ");
}
int main()
{
	int i, j;
	cin >> m >> n;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &tree[j]);
		if(isMaxHeap(0)) printf("Max Heap\n");
		else if(isMinHeap(0)) printf("Min Heap\n");
		else printf("Not Heap\n");
		postOrder(0);
		printf("\n");
	}
	return 0;
}
