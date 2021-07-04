#include <iostream>
#define MAX 500

using namespace std;
int matrix[MAX + 2][MAX + 2];
int dp[MAX + 2][MAX + 2] = { -1, };
//���� �迭�� �ڵ����� 0���� �ʱ�ȭ�ȴ�
//{ 0, }�� �ƴ� { -1, }���� ��ü�� -1�� �ʱ�ȭ�Ϸ� �ص� {-1, 0, 0}���� �ʱ�ȭ�ȴ�. memory ����� memset�� �̿�����
int m, n;
//�˰��� > top down ����� ���� ������ �ذ�����. dp[0][0] = 1�̶�� �ϰ� �Ʒ��� ����� ���Ѵ�.
//���������� ��ͷ� ���������� �����Ͽ�, �ֺ��� ����� �ڽź��� ���� ��Ͽ� �ڽ��� ���Ѵ�. 

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
	//����� ȯ�濡���� ������� ���� �迭�� ���� �������ٵ� �а� ������ segmentaion fault������ ���� ������ �� �ִ�
	//�ٸ� ���� ���α׷����� ���۵Ǿ��� ��쿡�� ������ �߻��ϹǷ� index out of bound�� ��������
}

int main(void) {
	cin >> m >> n;
	for (int i = 1; i < m + 1; i++) { //����
		for (int j = 1; j < n + 1; j++) { //����
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i < m + 1; i++) { //����
		for (int j = 1; j < n + 1; j++) { //����
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