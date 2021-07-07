#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#define MAX 110
using namespace std;

int n, m, tc;
int cnt;
int temp;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		cnt = 0;
		cin >> n >> m; //m이 몇번째로 나오는지 궁금한 상황
		for (int i = 0; i < n; i++) {
			cin >> temp;
			q.push(make_pair(i, temp));
			pq.push(temp);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int num = q.front().second;
			q.pop();
			if (pq.top() == num) {
				pq.pop();
				++cnt;
				if (idx == m) break;
			}
			else {
				q.push(make_pair(idx, num));
			}
		}
		cout << cnt << '\n';
	}
}