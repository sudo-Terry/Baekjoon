#include <iostream>
#include <cmath>
using namespace std;

int tc, n, ans;

void solve() {
	n--;
	int a = 2 * n + 1;
	ans = (sqrt(a) - 1) / 2;
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n; ans = 0;
		solve();
		cout << ans << '\n';
	}
	return 0;
}