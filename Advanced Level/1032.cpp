#include <iostream>
using namespace std;
typedef struct Node{
	char c;
	int next;
	bool flag;
}Node;
int main()
{
	int s1, s2, n, head, next;
	char c;
	cin >> s1 >> s2 >> n;	
	Node node[100010];
	for(int i = 0; i < n; i++){
		scanf("%d %c %d", &head, &c, &next);
		node[head].c = c;
		node[head].next = next;
		node[head].flag = false;
	}
	int p, suffix = -1;
	for(p = s1; p != -1; p = node[p].next)
		node[p].flag = true;
	for(p = s2; p != -1; p = node[p].next)
		if(node[p].flag == true) {
			suffix = p;
			break;
		}
	if(suffix != -1) printf("%05d", suffix);
	else printf("%d", suffix);
	return 0;
}
