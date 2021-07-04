#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int n, k;
ll ans = 0;
ll maxH = 0;
vector<ll> lan;
ll mid;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	ll temp;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		lan.push_back(temp);
		if (lan[i] > maxH)
			maxH = lan[i];
	}
	ll low = 1;
	ll high = maxH;
	while (low <= high) {
		mid = (low + high) / 2;
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			if (lan[i] >= mid)
				sum += lan[i] / mid;
		}
		if (sum >= n) { //랜선의 수가 n개보다 많음(정답이지만 최대 길이를 찾아야함)
			low = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}