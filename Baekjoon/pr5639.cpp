#include <iostream>
using namespace std;

//�˰��� >> 
//������ȸ ����� ���� ù��° ���� ��Ʈ����̸� �� �ڿ��� ���� ����Ʈ���� ��Ʈ�� ��ġ�ϰ� ���� ����Ʈ���� ���� �ڿ��� ������ ����Ʈ���� ��Ʈ�� ��ġ��
//���� ������ ���: ��Ʈ��� + ��Ʈ��庸�� ���� ����(���� ����Ʈ��) + ��Ʈ��庸�� ū ����(������ ����Ʈ��)
//�� ������� ��Ʈ��带 ���ÿ� �ְ� ������ ����Ʈ���� ���� ����Ʈ���� ������� ���ʴ�� �����

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