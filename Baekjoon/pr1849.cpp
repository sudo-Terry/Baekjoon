#include <iostream>
#define MAX 100100
using namespace std;

int n;
int A[MAX];
int segTree[MAX * 2];

/*
1���� ���ʷ� ������ ��ġ�Ѵٰ� �Ҷ� A[i]�� ����ŭ �տ� ��ĭ�� �������
A[1]�� 5�̸� ? ? ? ? ? 1 ? ? ? ...
A[2]�� 7�̸� ? ? ? ? ? 1 ? ? 2 ...
*/

void solve(int num, int idx) {
	if (num >= n) {//���� ����� ���
		updateTree(num, -1);
		cout << num - n << '\n';
	}
}

void updateTree(int node, int val) {
	if (node < 1) return;
	segTree[node] += val;
	updateTree(node / 2, val);
}

void init() {
	for (int i = n; i < n * 2; i++)
		segTree[i] = 1;
	for (int i = n - 1; i > 0; i--)
		segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	init();
	for (int i = 1; i <= n; i++) {
		solve(1, i);
	}
	return 0;
}