#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct Node{
	int val, id;
}Node;
vector<Node> v;
vector<int> in, post;
int getHeight(int id)
{
	int h;
	for(h = 1; pow(2, h) <= id; h++);
	return h;
}
bool cmp(Node q, Node p)
{
	return q.id < p.id;	
}
bool cmp1(Node q, Node p)
{
	int qH = getHeight(q.id);
	int pH = getHeight(p.id);
	if(qH != pH) return qH < pH;
	else{
		if(qH % 2 == 1) return q.id > p.id;
		else return q.id < p.id;
	}
}
void getNode(int inLeft, int inRight, int postLeft, int postRight, int id)
{
	if(inLeft == inRight){
		Node n = {in[inLeft], id};
		v.push_back(n);
		return ;
	}
	if(inRight > inLeft)
	{
		int i = inLeft;
		while(i <= inRight && in[i] != post[postRight]) i++;
		Node n = {in[i], id};
		v.push_back(n);
		getNode(inLeft, i-1, postLeft, postLeft + (i - inLeft) - 1, id*2);
		getNode(i+1, inRight, postLeft+(i-inLeft), postRight-1, id*2+1);
	}
}
int main()
{
	int n,i;
	cin >> n;
	in.resize(n);
	post.resize(n);
	for(i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &post[i]);		
	getNode(0, n-1, 0, n-1, 1);
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.end(), cmp1);
	for(i = 0; i < v.size(); i++)
	{
		if(i != 0) printf(" ");
		printf("%d", v[i].val);
	}
	return 0;
}
