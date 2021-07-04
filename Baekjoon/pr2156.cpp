#include <iostream>
#define MAX 10000

using namespace std;
int n = 0;
int drink[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//알고리즘 > n번째 포도주를 마셨을 경우 
//1) n - 1번째 포도주를 마시면 n - 2번째는 무조건 못마시므로 n - 3번째 부터 3)반복 getMax[n] = drink[n] + drink[n - 1] + getMax(n - 3)
//2) n - 1번째 포도주를 안마시면 n - 2번째부터 3) 반복 getMax(n) = drink[n] + getMax(n - 2)
//3) n번째 포도주를 안마시면 n-1번째 포도주에 대해 판단을 반복 getMax(n) = getMax(n - 1)
/*
int getMax(int n) {
	if (dp[n])//memoization
		return dp[n];
	if (dp[n] < dp[n - 2] + drink[n])
		return dp[n] = getMax(n - 2) + drink[n];
	if (dp[n] < drink[n] + drink[n - 1] + dp[n - 3])
		return dp[n] = drink[n] + drink[n - 1] + getMax(n - 3);
	return dp[n] = getMax(n-1);

}*/

int main(void) {

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> drink[i];
	}
	
	dp[0] = 0;
	dp[1] = drink[1];
	dp[2] = drink[1] + drink[2];

	for (size_t i = 3; i < n + 1; i++) {
		dp[i] = dp[i - 1]; //안마실 경우
		if (dp[i] < dp[i - 2] + drink[i])
			dp[i] = dp[i - 2] + drink[i];
		if (dp[i] < drink[i] + drink[i - 1] + dp[i - 3])
			dp[i] = drink[i] + drink[i - 1] + dp[i - 3];
	}

	cout << dp[n];
	return 0;
}