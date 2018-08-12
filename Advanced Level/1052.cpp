#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int addr, val, next;
}node[100010];
vector<struct Node> v;
bool cmp(struct Node q, struct Node p)
{
	return q.val < p.val;
}
int main()
{
	int n, i, head, addr, val, next;
	cin >> n >> head;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d", &addr, &val, &next);
		node[addr].addr = addr;
		node[addr].val = val;
		node[addr].next = next;
	}
	int temp = head;
	while(temp != -1) {
		v.push_back(node[temp]);
		temp = node[temp].next; 
	}
	sort(v.begin(), v.end(), cmp);
	if(v.size() == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", v.size(), v[0].addr);
	for(i = 0; i < v.size(); i++)
	{
		if(i != v.size()-1) printf("%05d %d %05d\n", v[i].addr, v[i].val, v[i+1].addr);
		else printf("%05d %d -1", v[i].addr, v[i].val);
	}
	return 0;
}
