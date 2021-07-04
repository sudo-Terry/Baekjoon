#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000
#define RIPEN 1
#define NOTRIPEN 0
#define EMPTY -1

using namespace std;

queue<pair<int, int>> q;
int tomato[MAX + 2][MAX + 2];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 }; // middle up right down left
int m, n;
int days = 0;

void solve() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (tomato[ny][nx] == NOTRIPEN && ny<=n && nx <= m && nx>=1 && ny>=1) {
				tomato[ny][nx] = tomato[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == RIPEN)
				q.push(make_pair(i, j));
		}
	}
	solve();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tomato[i][j] == NOTRIPEN) {//토마토 상태에 변화가 없는데 안익은게 있으면 -1출력
				cout << "-1" << '\n';
				return 0;
			}
			if (days < tomato[i][j])
				days = tomato[i][j];
		}
	}
	cout << days - 1 << '\n';
	return 0;
}