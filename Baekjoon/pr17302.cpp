#include <iostream>
#include <vector>
#include <string>
#define MAX 2000

// 검정: 홀수        하양: 짝수

int n, m;
int matrix[MAX + 1][MAX + 1] = { 0, };
using namespace std;

//알고리즘 >> 2번 3번 행동을 한번씩 취할 경우 선택한 방의 색만 바뀌게 된다
// 2번 3번만을 이용하여 색변환을 하면 상하좌우에 짝수개의 블록이 있을 경우 짝수번 간섭을 받아 결과적으로 영향이 없다.
// 반대로 상하좌우에 홀수개의 블록이 있을 경우, 직접 변경한 중앙색의 반대로 색이 정해진다.

int checkBlock(int i, int j) { //인접한 블록의 수 >> 짝수면 그대로 홀수면 주변블록에 의해 바뀜 
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
			if (status[i].at(j) == 'W') {//블록이 하양인데 인접블록수가 홀수면 3번행위 짝수면 2번행위
				if (checkBlock(i, j) % 2 == 1)
					matrix[i][j] = 3;
				else
					matrix[i][j] = 2;
			}
			else { //블록이 검정인데 인접블록수가 홀수면 2번행위 짝수면 3번행위
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