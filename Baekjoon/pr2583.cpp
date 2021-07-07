#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 110
#define VISITED 1

int m, n, k;
int area[MAX][MAX];
bool visited[MAX][MAX];
vector<int> s;
queue<pair<int, int>> q;
int ans = 0, tempS = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 }; // middle up right down left

void bfs() {
	tempS = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		tempS++;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (area[ny][nx] != VISITED && ny < m && nx < n && nx >= 0 && ny >= 0) {
				q.push(make_pair(ny, nx));
				area[ny][nx] = VISITED;
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> m >> n >> k;    //      m: y     n: x
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int l = x1; l < x2; l++) {
				area[j][l] = VISITED;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] != VISITED) {
				area[i][j] = VISITED;
				q.push(make_pair(i, j));
				bfs();
				ans++;
				s.push_back(tempS);
			}
		}
	}
	cout << ans << '\n';
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	return 0;
}
