#include <iostream>
#include <cstring>
#include <cstdio>  
#include <functional>  
#include <string>
#include <queue>
#define MAX 110
using namespace std;

int n, tc, temp, ans;
int level[MAX];
priority_queue<int, vector<int>, greater<int> > pq;

void solve() {
	for (int i = 1; i <= n; i++) {
		pq.push(level[i]);
	}
	int lowLV = pq.top(); pq.pop();
	while (1) {
		if (pq.empty())
			break;
		int nextLV = pq.top();
		if (lowLV == nextLV) 
			pq.pop();
		else
			break;
	}
	ans = pq.size();
	while (!pq.empty()) {
		pq.pop();
	}
}

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> temp;
			level[i] = temp;
		}
		solve();
		cout << ans << '\n';
	}
	return 0;
}