#include <iostream>
#define MAX 1100
using namespace std;

int matrix[MAX][MAX];
int sum[MAX][MAX];
int n, m, x_1, y_1, x_2, y_2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> matrix[i][j];
		}
	}
	sum[1][1] = matrix[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cout << sum[x_2][y_2] - sum[x_1 - 1][y_2] - sum[x_2][y_1 - 1] + sum[x_1 - 1][y_1 - 1] << '\n';
	}
	return 0;
}