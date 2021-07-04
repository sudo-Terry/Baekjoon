#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_K 10000

using namespace std;
int memo[MAX_K + 1] = { 0, };
vector<int> coins;
//알고리즘 > k원의 동전수 = coins[i]원 1개 + (k-coins[i])원의 동전 수 

int get_Coin(int k) {
	int temp = 0;
	int min = INT_MAX;
	if (k < 0)
		return 10001;
	if (memo[k] || k==0)
		return memo[k];
	for (int i = 0; i < coins.size(); i++) {
		temp = get_Coin(k - coins[i]) + 1;
		if (temp < min)
			min = temp;
		return memo[k] = min;
	}
}

int main(void) {
	int n, k;
	int tempCoin = 0;
	int min = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tempCoin;
		coins.push_back(tempCoin);
	}
	sort(coins.begin(), coins.end());

	min = get_Coin(k);
	if (min == 0 || min == 10001) {

	}
	else {
		cout << min;
	}

	return 0;
}