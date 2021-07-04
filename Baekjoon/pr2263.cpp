#include <iostream>
#define MAX 100000
using namespace std;

//�˰��� >> ����Ʈ���������� ������ ������ ���� ��Ʈ�̹Ƿ� Ʈ���� ��Ʈ�� �� �� �ִ�.
//�ο��� �Ŀ����� ��Ʈ���ڸ� �������� ������ ��� ���ڵ��� ���� ����Ʈ��(�׷� left), �������� ��� ���ڵ��� ������ ����Ʈ���� ����ȣ�̴�(�׷� right)
//����Ʈ �������� �� (�׷�left ����ȣ���� ����) + (�׷�right ����ȣ���� ����) + ��Ʈ �� ���� ������ �� �ִ�.
//������ ����Ʈ��, ��, �׷� right�� ����ȣ ������ ������ ���ڵ� �ᱹ ������ ����Ʈ���� ��Ʈ������� �� �� �ִ�.
//�̷� ���� �ٽ� �׷��� ���� ��Ʈ�� ��� �����ϴٺ��� �׷����� ���¸� �� �� �ְ� �׷��� ������ 2�� ���� ������ ��� �׷����� �������� ���¸� ������ �� �ִ�

int n;
int inorder[MAX + 1];
int postorder[MAX + 1];
int preorder[MAX + 1];
int index[MAX + 1];

void solve(int begin1, int end1, int begin2, int end2) {
	if (begin1 > end1 || begin2 > end2)
		return;
	int root = postorder[end2]; //����Ʈ ������ ������ ���� �׻� Ʈ���� ��Ʈ
	cout << root << " "; //���������� ù���� �׻� Ʈ���� ��Ʈ
	int rootindex = index[root];
	int temp = rootindex - begin1;
	solve(begin1, rootindex - 1, begin2, begin2 + temp - 1); //���� �׷�
	solve(rootindex+1, end1, begin2 + temp, end2 - 1); //������ �׷�
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inorder[i];
	for (int i = 0; i < n; i++)
		cin >> postorder[i];
	for (int i = 0; i < n; i++)
		index[inorder[i]] = i;

	solve(0, n - 1, 0, n - 1);
	return 0;
}