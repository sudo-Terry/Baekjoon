#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 110
#define VISITED 1

int n;
int area[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;
int ans = 0, maxAns = 0, maxRain;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 }; // middle up right down left

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!visited[ny][nx] && ny < n && nx < n && nx >= 0 && ny >= 0) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			if (area[i][j] > maxRain) maxRain = area[i][j];
		}
	}
	for (int rain = 0; rain <= maxRain; rain++) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
				if (area[i][j] < rain) visited[i][j] = true;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					q.push(make_pair(i, j));
					bfs();
					ans++;
				}
			}
		}
		if (ans > maxAns) maxAns = ans;
	}
	if (maxAns == 0) maxAns = 1;
	cout << maxAns << '\n';
	return 0;
}
