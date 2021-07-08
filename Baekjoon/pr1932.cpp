#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#define MAX 510
using namespace std;

int n, m, x, y, k;
int dp[MAX][MAX];
int input[MAX][MAX];
int dpMax = 0;

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] += dp[i - 1][j];
			}else if (j == i) {
				dp[i][j] += dp[i - 1][j - 1];
			}else {
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	//rootNode == dp[1][1]
	//childOfRoot == dp[2][1] || dp[2][2]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}
	solve();
	for (int i = 1; i <= n; i++)if (dp[n][i] > dpMax) dpMax = dp[n][i];
	cout << dpMax;
}