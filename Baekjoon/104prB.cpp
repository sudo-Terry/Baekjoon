#include <iostream>
using namespace std;

int tc, n, k, ans;

void solve() {
	if (n % 2) {
		int temp = n / 2;
		ans = (((k - 1) / temp) + k - 1) % n + 1;
	}
	else {
		ans = (k - 1) % n + 1;
	}
}

int main() {
	cin >> tc;
	while (tc--) {
		ans = 0;
		cin >> n >> k;
		solve();
		cout << ans << '\n';
	}
	return 0;
}