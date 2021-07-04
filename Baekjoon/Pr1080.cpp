#include <iostream>
#include <algorithm>

using namespace std;

int matrixA[50][50];
int matrixB[50][50];

inline void reverseMatrix(int y, int x) {
	for (int i = y ; i <= y + 2; i++) {
		for (int j = x ; j <= x + 2; j++) {
			if (matrixA[i][j] == 0) { //0이면 1
				matrixA[i][j] = 1;
			}
			else if(matrixA[i][j] == 1){ //1이면 0으로
				matrixA[i][j] = 0;
			}
		}
	}
}

int main(void) {
	int min = 0; //
	int m, n;
	char temp; 
	
	cin >> m >> temp >> n; //xy 입력
	for (int i = 0; i < m; i++) { //A입력
		for (int j = 0; j < n; j++) {
			cin >> matrixA[i][j];
		}
	}
	for (int i = 0; i < m; i++) { //B입력
		for (int j = 0; j < n; j++) {
			cin >> matrixB[i][j];
		}
	}

	for (int i = 0; i < m - 2; i++) { //[i][j]의 좌표에서 다르면 최솟값+1 하고 뒤집기
		for (int j = 0; j < n - 2; j++) {
			if (matrixA[i][j] != matrixB[i][j]) {
				reverseMatrix(i, j);
				min++;
			}
		}
	}
	for (int i = 0; i < m; i++) { //전부 뒤집었는데 A, B다르면 -1을 return 
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