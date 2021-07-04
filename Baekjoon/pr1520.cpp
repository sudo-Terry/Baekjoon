#include <iostream>
#define MAX 500

using namespace std;
int matrix[MAX + 2][MAX + 2];
int dp[MAX + 2][MAX + 2] = { -1, };
//전역 배열은 자동으로 0으로 초기화된다
//{ 0, }이 아닌 { -1, }으로 전체를 -1로 초기화하려 해도 {-1, 0, 0}으로 초기화된다. memory 헤더의 memset을 이용하자
int m, n;
//알고리즘 > top down 방식을 통해 문제를 해결하자. dp[0][0] = 1이라고 하고 아래의 방식을 취한다.
//종착점에서 재귀로 시작점까지 도달하여, 주변의 블록중 자신보다 작은 블록에 자신을 더한다. 

int dfs(int i, int j) {
	if (dp[i][j] != -1) //memoization
		return dp[i][j];
	if (i <= 0 || i > m || j <= 0 || j > n) //array out of bound
		return 0;
	if (i == 1 && j == 1) //root node
		return dp[i][j] = 1;

	dp[i][j] = 0;
	if(matrix[i][j] < matrix[i + 1][j]) //down
		dp[i][j] += dfs(i + 1, j);
	if (matrix[i][j] < matrix[i][j + 1]) //right
		dp[i][j] += dfs(i, j + 1);
	if (matrix[i][j] < matrix[i - 1][j]) // up
		dp[i][j] += dfs(i - 1, j);
	if (matrix[i][j] < matrix[i][j - 1]) //left
		dp[i][j] += dfs(i, j - 1);
	return dp[i][j];
	//디버깅 환경에서는 디버깅을 위해 배열이 실제 공간보다도 넓게 잡혀서 segmentaion fault오류가 나도 안잡힐 수 있다
	//다만 실제 프로그램으로 제작되었을 경우에는 오류가 발생하므로 index out of bound를 조심하자
}

int main(void) {
	cin >> m >> n;
	for (int i = 1; i < m + 1; i++) { //세로
		for (int j = 1; j < n + 1; j++) { //가로
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i < m + 1; i++) { //세로
		for (int j = 1; j < n + 1; j++) { //가로
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < m + 2; i += m + 1) {
		for (int j = 0; j < n + 2; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j += n + 1) {
			matrix[i][j] = 0;
		}
	}
	cout << dfs(m, n) << endl;

	return 0;
}