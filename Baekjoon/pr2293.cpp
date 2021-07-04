#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;
vector<int> coins;
int dp[MAX + 1] = { 0, };

// 알고리즘 > k원의 경우의 수 = P(k)
// P(K, i) = P(K, i-1) + P(K -  coins[i], i)
// P(K -  coins[i], i) : 일반 재귀
// P(K, i-1) :  i-1 = 0까지 내려가서 가장 싼 코인만 이용하여 계산하고 재귀

int get_coin(int k, int i) { // coins[0] ~ coins[i]를 이용하여 k원을 만들 수 있는 경우의 수
	if (dp[k]) //메모
		return dp[k];
	if (k == coins[i])
		return dp[k] += 1;
	else {
		if ((k <= coins[i]) && (i <= 0))
			return 0;
		else if (k <= coins[i])
			return dp[k] += get_coin(k, i - 1) + 0;
		else if (i <= 0)
			return dp[k] += 0 + get_coin(k - coins[i], i);
		else
			return dp[k] += get_coin(k, i - 1) + get_coin(k - coins[i], i);
	}
}

int main(void) {
	int n, k;
	int tempint;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tempint;
		coins.push_back(tempint);
	}

	//cout << get_coin(k, n - 1);

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= k; j++)
			dp[j] += + dp[j - coins[i]];
	
	cout << dp[k];

	return 0;
}