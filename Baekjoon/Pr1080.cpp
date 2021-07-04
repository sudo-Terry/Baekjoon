#include <iostream>
#include <algorithm>

using namespace std;

int matrixA[50][50];
int matrixB[50][50];

inline void reverseMatrix(int y, int x) {
	for (int i = y ; i <= y + 2; i++) {
		for (int j = x ; j <= x + 2; j++) {
			if (matrixA[i][j] == 0) { //0�̸� 1
				matrixA[i][j] = 1;
			}
			else if(matrixA[i][j] == 1){ //1�̸� 0����
				matrixA[i][j] = 0;
			}
		}
	}
}

int main(void) {
	int min = 0; //
	int m, n;
	char temp; 
	
	cin >> m >> temp >> n; //xy �Է�
	for (int i = 0; i < m; i++) { //A�Է�
		for (int j = 0; j < n; j++) {
			cin >> matrixA[i][j];
		}
	}
	for (int i = 0; i < m; i++) { //B�Է�
		for (int j = 0; j < n; j++) {
			cin >> matrixB[i][j];
		}
	}

	for (int i = 0; i < m - 2; i++) { //[i][j]�� ��ǥ���� �ٸ��� �ּڰ�+1 �ϰ� ������
		for (int j = 0; j < n - 2; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				reverseMatrix(i, j);
				min++;
			}
		}
	}
	for (int i = 0; i < m; i++) { //���� �������µ� A, B�ٸ��� -1�� return 
		for (int j = 0; j < n; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << min;
	return 0;
}