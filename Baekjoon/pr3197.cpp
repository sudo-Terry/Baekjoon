#include<iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 1510
using namespace std;

queue<pair<int, int>> q;
char map[MAX][MAX];
pair<int, int> par[MAX][MAX];
bool visited[MAX][MAX];
pair<int, int> start_L, end_L;
int dx[4] = { 0, 0, - 1, 1 }; int dy[4] = { 1, -1, 0, 0 };// ╩С го аб ©Л
int c, r, ans = 0;

pair<int, int> find(pair<int, int> p) {
	if (par[p.first][p.second] == p) 
		return p;
	return par[p.first][p.second] = find(par[p.first][p.second]);
}

void merge(pair<int, int> a, pair<int, int> b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[a.first][a.second] = b;
	}
}

void bfs() {
	while (int qc = q.size()) {
		memset(visited, false, sizeof(visited));
		while (qc--) {
			//cout << qc << '\n';
			int y = q.front().first;
			int x = q.front().second;
			//cout << x << "   " << y << '\n';
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (nx <= 0 || nx > r || ny <= 0 || ny > c)
					continue;
				if (map[ny][nx] == 'X') {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					map[ny][nx] = '.';
				}
				else {
					if (!visited[ny][nx]) 
						merge(find(make_pair(y, x)), find(make_pair(ny, nx)));
				}
			}
		}
		if (find(start_L) == find(end_L)) {
			cout << ans;
			return;
		}
		ans++;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	bool flag = true;
	cin >> c >> r;
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			par[i][j] = make_pair(i, j);
		}
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			cin >> map[i][j];
			if (map[i][j] == '.') {
				q.push(par[i][j]);
			}
			else if (map[i][j] == 'L') {
				map[i][j] = '.';
				q.push(par[i][j]);
				if (flag) {
					start_L = par[i][j];
					flag = false;
				}
				else
					end_L = par[i][j];
			}
		}
	}
	//cout << q.size();
	//cout << start_L.first << " " << start_L.second << '\n';
	//cout << end_L.first << " " << end_L.second << '\n';
	bfs();
	return 0;
}