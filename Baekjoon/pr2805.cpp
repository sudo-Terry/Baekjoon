#include <iostream>
#define MAX 1000100
typedef long long ll;
using namespace std;

int n, m, maxH;
int h[MAX];
int mid;
int ans = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m; // n: 나무의 수 m: 필요한 나무 길이
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] > maxH)
			maxH = h[i];
	}
	int left = 0;
	int right = maxH;
	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			if (h[i] > mid)
				sum += h[i] - mid;
		}
		if (sum >= m) {
			left = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}