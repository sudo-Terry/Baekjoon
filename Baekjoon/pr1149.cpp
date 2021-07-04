#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int n;
vector<int> red;
vector<int> green;
vector<int> blue;
int dp[MAX + 1][3];

void solve() {
	dp[1][0] = red[0]; dp[1][1] = green[0]; dp[1][2] = blue[0];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1][1] <= dp[i - 1][2]) //red
			dp[i][0] = dp[i - 1][1] + red[i - 1];
		else
			dp[i][0] = dp[i - 1][2] + red[i - 1];
		if (dp[i - 1][0] <= dp[i - 1][2]) //green
			dp[i][1] = dp[i - 1][0] + green[i - 1];
		else
			dp[i][1] = dp[i - 1][2] + green[i - 1];
		if (dp[i - 1][1] <= dp[i - 1][0]) //blue
			dp[i][2] = dp[i - 1][1] + blue[i - 1];
		else
			dp[i][2] = dp[i - 1][0] + blue[i - 1];
	}
}

int main() {
	int tempCost;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tempCost; red.push_back(tempCost);
		cin >> tempCost; green.push_back(tempCost);
		cin >> tempCost; blue.push_back(tempCost);
	}
	solve();
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
	return 0;
}