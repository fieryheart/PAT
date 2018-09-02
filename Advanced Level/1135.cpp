#include <iostream>
#include <malloc.h>
using namespace std;
int k, n;
typedef struct TreeNode* node;
struct TreeNode{
	int val;
	node left, right;
};
node insert(node root, int num)
{
	if(root == NULL) {
		root = (node)malloc(sizeof(node));
		root->val = num;
		root->left = root->right = NULL;
	} else if(abs(num) < abs(root->val)) {
		root->left = insert(root->left, num);
	} else if(abs(num) > abs(root->val)) {
		root->right = insert(root->right, num);
	}
	return root;
}
bool isRootBlack(node root)
{
	if(root->val < 0) return false;
	else return true;
}
bool isRedHasBlackChild(node root)
{
	if(root == NULL) return true;
	if(root->val < 0) {
		if(root->left != NULL && root->left->val < 0) return false;
		if(root->right != NULL && root->right->val < 0) return false;
	}
	return isRedHasBlackChild(root->left) && isRedHasBlackChild(root->right);
}
int getBlackNode(node root)
{
	if(root == NULL) return 0;
	int left = getBlackNode(root->left);
	int right = getBlackNode(root->right);
	return root->val > 0 ? max(left, right)+1 : max(left, right);
}
bool isSameBlack(node root)
{
	if(root == NULL) return true;
	int left = getBlackNode(root->left);
	int right = getBlackNode(root->right);
	if(left != right) return false;
	else return isSameBlack(root->left) && isSameBlack(root->right);
}
void freeTree(node root)
{
	if(root->left) freeTree(root->left);
	if(root->right) freeTree(root->right);
	free(root);
}
int main()
{
	int i, j, num;
	cin >> k;
	for(i = 0; i < k; i++)
	{
		cin >> n;
		node root = NULL;
		for(j = 0; j < n; j++)
		{
			scanf("%d", &num);
			root = insert(root, num);
		}
		bool flag = isRootBlack(root) && isRedHasBlackChild(root) && isSameBlack(root);
		if(flag == true) cout << "Yes" << endl;
		else cout << "No" << endl;
		freeTree(root);
	}
	return 0;
}
