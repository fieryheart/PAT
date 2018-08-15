#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct TreeNode* node;
struct TreeNode{
	int val;
	node left, right;
};
node rotateLeft(node root)
{
	node temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp; 
}
node rotateRight(node root)
{
	node temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}
node rotateLeftRight(node root)
{
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}
node rotateRightLeft(node root)
{
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}
int getHeight(node root)
{
	if(root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node insert(node root, int num)
{
	if(root == NULL)
	{
		root = (node)malloc(sizeof(node));
		root->val = num;
		root->left = root->right = NULL;
	} else if(num < root->val) {
		root->left = insert(root->left, num);
		if(abs(getHeight(root->left) - getHeight(root->right)) > 1)
			root = num < root->left->val ? rotateRight(root) : rotateLeftRight(root);
	} else {
		root->right = insert(root->right, num);
		if(abs(getHeight(root->right) - getHeight(root->left)) > 1)
			root = num > root->right->val ? rotateLeft(root) : rotateRightLeft(root); 
	}
	return root;
}
int main()
{
	int n,i,num;
	cin >> n;
	node root = NULL;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num);
		root = insert(root, num);
	}
	printf("%d", root->val);
	return 0;
}
