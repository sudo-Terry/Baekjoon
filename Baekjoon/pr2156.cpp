#include <iostream>
#define MAX 10000

using namespace std;
int n = 0;
int drink[MAX + 1] = { 0, };
int dp[MAX + 1] = { 0, }; //memoization

//�˰��� > n��° �����ָ� ������ ��� 
//1) n - 1��° �����ָ� ���ø� n - 2��°�� ������ �����ùǷ� n - 3��° ���� 3)�ݺ� getMax[n] = drink[n] + drink[n - 1] + getMax(n - 3)
//2) n - 1��° �����ָ� �ȸ��ø� n - 2��°���� 3) �ݺ� getMax(n) = drink[n] + getMax(n - 2)
//3) n��° �����ָ� �ȸ��ø� n-1��° �����ֿ� ���� �Ǵ��� �ݺ� getMax(n) = getMax(n - 1)
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
		dp[i] = dp[i - 1]; //�ȸ��� ���
		if (dp[i] < dp[i - 2] + drink[i])
			dp[i] = dp[i - 2] + drink[i];
		if (dp[i] < drink[i] + drink[i - 1] + dp[i - 3])
			dp[i] = drink[i] + drink[i - 1] + dp[i - 3];
	}

	cout << dp[n];
	return 0;
}