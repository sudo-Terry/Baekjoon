#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#define MAX 1000100
#define INF 987654321
using namespace std;

int n, m, x, y, k;
int dp[MAX];

void solve() {
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = i - 1; 
	}
	solve();
	cout << dp[n] << '\n';
	return 0;
}