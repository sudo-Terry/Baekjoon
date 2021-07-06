#include <iostream>
#include <queue>
using namespace std;
#define MAX 100100

int n, ans = 0;
int bundle[MAX];
priority_queue<int> pq;

void solve() {
	ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		pq.push(-bundle[i]);
	}
	while (!pq.empty()) {
		if (cnt == n - 1)break;
		int num1 = -pq.top();
		pq.pop();
		int num2 = -pq.top();
		pq.pop();
		ans += num1 + num2;
		pq.push(-(num1 + num2));
		cnt++;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bundle[i];
	}
	solve();
	return 0;
}
