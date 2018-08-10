#include <iostream>
#include <malloc.h>
#include <vector>
using namespace std;
vector<int> pre, post, ppre;
typedef struct TreeNode* tree;
struct TreeNode {
	int val;
	tree left, right;
};
tree insert(tree root, int val)
{
	if(root == NULL) {
		root = (tree)malloc(sizeof(tree));
		root->val = val;
		root->left = root->right = NULL;
	} else if(val < root->val) {
		root->left = insert(root->left, val);
	} else if(val >= root->val) {
		root->right = insert(root->right, val);
	}
	return root;
}
tree doMirror(tree root)
{
	if(root == NULL) return 0;
	tree temp = NULL;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	doMirror(root->left);
	doMirror(root->right);
	return root;
}
void preorder(tree root)
{
	if(root == NULL) return;
	ppre.push_back(root->val);
	preorder(root->left);
	preorder(root->right);
}
void postorder(tree root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->val);
}
int main()
{
	int n, i, num;
	tree bst, mbst;
	bst = mbst = NULL;
	cin >> n;	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		pre.push_back(num);
		bst = insert(bst, num);
	}
	if(bst == NULL) return 0;
	bool flag = true;
	preorder(bst);
	for(i = 0; i < n; i++)
		if(ppre[i] != pre[i]){
			flag = false;
			break;
		}
	if(flag == true){
		printf("YES\n");
		postorder(bst);
		for(i = 0; i < n; i++)
		{
			if(i!=0) printf(" ");
			printf("%d", post[i]);
		}
		return 0;
	}
	mbst = doMirror(bst);
	ppre.clear();
	flag = true;
	preorder(mbst);
	for(i = 0; i < n; i++)
		if(ppre[i] != pre[i]){
			flag = false;
			break;
		}
	if(flag == true){
		printf("YES\n");
		postorder(mbst);
		for(i = 0; i < n; i++)
		{
			if(i!=0) printf(" ");
			printf("%d", post[i]);
		}
		return 0;
	}
	printf("NO");
	return 0;
}
