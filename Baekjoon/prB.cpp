#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 110
using namespace std;

long long arr[MAX];
long long arrsum[MAX];
long long tc = 0, n, k, ans;

bool checkOver(long long tempArr, long long tempSum) {
	return tempArr * 100 > k * tempSum;
}

int main() {
	cin >> tc;
	while (tc--) {
		memset(arr, 0, sizeof(arr)); 
		memset(arrsum, 0, sizeof(arrsum));
		cin >> n >> k;
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		long long tmp = arr[1];
		for (int i = 2; i <= n; i++) {
			if (checkOver(arr[i], tmp)) {
				long long p0 = arr[i] * 100;
				if (p0 % k == 0) p0 = p0 / k;
				else p0 = p0 / k + 1;
				ans += p0 - tmp;
				tmp = p0;
			}
			tmp += arr[i];
		}
		cout << ans << '\n';
	}
	return 0;
}