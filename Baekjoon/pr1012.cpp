#include <iostream>
#include <queue>
using namespace std;
#define MAX 55
#define PLANTED 1
#define EMPTY 0

queue<pair<int, int>> q;
int tc, ans = 0;
int m, n, k;
bool visited[MAX][MAX];
int cabbage[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 }; // middle up right down left

void dfs() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (cabbage[i][j] == PLANTED && !visited[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (cabbage[ny][nx] == PLANTED && ny <= n && nx <= m && nx >= 1 && ny >= 1) { // adj is not out of bound
							if (!visited[ny][nx]) { //adj is not visited yet
								q.push(make_pair(ny, nx));
								visited[ny][nx] = true;
							}
						}
					}
				}
				ans++;
			}
			visited[i][j] = true;
		}
	}
}

void solve() {
	ans = 0;
	cin >> m >> n >> k;
	for (int i = 1; i <= n; i++) { //initialize
		for (int j = 1; j <= m; j++) {
			cabbage[i][j] = EMPTY;
			visited[i][j] = false;
		}
	}
	for (int i = 1; i <= k; i++) { //planted
		int col, row;
		cin >> row >> col;
		cabbage[col+1][row+1] = PLANTED;
	}
	dfs();
	cout << ans << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> tc;
	while (tc--) {
		solve();
	}
	return 0;
}
