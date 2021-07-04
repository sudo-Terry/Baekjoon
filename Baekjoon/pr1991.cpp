#include <iostream>
#include <stddef.h>
using namespace std;
//#define NULL 987654321

class Tree {
private:
    string data;
	Tree *left, *right;
public:
    Tree() {	
		data = ""; left = NULL; right = NULL;
	}
	void setData(char data) {
		this->data = data;
	}
	void setLeft(Tree* left) {
		this->left = left;
	}
	void setRight(Tree* right) {
		this->right = right;
	}
	void inorder(Tree* root) {
		if (root == NULL)
			return;
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
	void preorder(Tree* root) {
		if (root == NULL)
			return;
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
	void postorder(Tree* root) {
		if (root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
};

int main() {
	int n;
	char leftN, thisN, rightN;
	cin >> n;
	Tree *tree = new Tree[n];
	for (int i = 0; i < n; i++) {
		cin >> thisN >> leftN >> rightN;
		tree[(int)(thisN - 'A')].setData(thisN);
		if (leftN != '.')
			tree[(int)(thisN - 'A')].setLeft(&tree[(int)(leftN - 'A')]);
		if (rightN != '.')
			tree[(int)(thisN - 'A')].setRight(&tree[(int)(rightN - 'A')]);
	}
	tree->preorder(&tree[0]); cout << endl;
	tree->inorder(&tree[0]); cout << endl;
	tree->postorder(&tree[0]); cout << endl;
	return 0;
}