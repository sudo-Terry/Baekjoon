#include <iostream>
using namespace std;

//알고리즘 >> 
//전위순회 결과의 가장 첫번째 수는 루트노드이며 그 뒤에는 왼쪽 서브트리의 루트가 위치하고 왼쪽 서브트리의 노드들 뒤에는 오른쪽 서브트리의 루트가 위치함
//전위 순위의 결과: 루트노드 + 루트노드보다 작은 수들(왼쪽 서브트리) + 루트노드보다 큰 수들(오른쪽 서브트리)
//위 결과에서 루트노드를 스택에 넣고 오른쪽 서브트리와 왼쪽 서브트리를 대상으로 차례대로 재귀함

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Node* root = NULL;
	int val;
	while (cin >> val) {
		if (val == EOF) break;
		root = insert(root, val);
	}
	postorder(root);
	return 0;
}