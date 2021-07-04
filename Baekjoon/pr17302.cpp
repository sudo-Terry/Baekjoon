#include <iostream>
#include <vector>
#include <string>
#define MAX 2000

// ����: Ȧ��        �Ͼ�: ¦��

int n, m;
int matrix[MAX + 1][MAX + 1] = { 0, };
using namespace std;

//�˰��� >> 2�� 3�� �ൿ�� �ѹ��� ���� ��� ������ ���� ���� �ٲ�� �ȴ�
// 2�� 3������ �̿��Ͽ� ����ȯ�� �ϸ� �����¿쿡 ¦������ ����� ���� ��� ¦���� ������ �޾� ��������� ������ ����.
// �ݴ�� �����¿쿡 Ȧ������ ����� ���� ���, ���� ������ �߾ӻ��� �ݴ�� ���� ��������.

int checkBlock(int i, int j) { //������ ����� �� >> ¦���� �״�� Ȧ���� �ֺ���Ͽ� ���� �ٲ� 
	int k = 4;
	if (i == 0)
		k--;
	if (i == n-1)
		k--;
	if (j == 0)
		k--;
	if (j == m-1)
		k--;
	return k;
}

int main(void) {

	string input;
	vector<string> status;

	// m =>string length
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input; 
		status.push_back(input);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (status[i].at(j) == 'W') {//����� �Ͼ��ε� ������ϼ��� Ȧ���� 3������ ¦���� 2������
				if (checkBlock(i, j) % 2 == 1)
					matrix[i][j] = 3;
				else
					matrix[i][j] = 2;
			}
			else { //����� �����ε� ������ϼ��� Ȧ���� 2������ ¦���� 3������
				if (checkBlock(i, j) % 2 == 1)
					matrix[i][j] = 2;
				else
					matrix[i][j] = 3;
			}
		}
	}

	cout << 1 << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}