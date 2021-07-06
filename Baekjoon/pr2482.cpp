#include <iostream>
#include <cstring>
#define MAX 1050
#define TENBIL 1000000003
typedef long long ll;
using namespace std;

int dp[MAX][MAX]; //dp[a][b] : a��¥�� ����ȯ���� b���� �� ����
int ans = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % TENBIL;
		}
	}
	//n��° ĭ�� ĥ���� �ʴ� ��� + n��° ĭ�� ĥ�ϴ� ���
	//ans = (dp[n - 1][k] + dp[n - 3][k - 1]) % TENBIL;

	cout << ans << '\n';
}