#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 300

int gameboard[MAX][MAX];
bool visited[MAX][MAX];
int move_x[8] = { 2, 1, -2, -1, -1, -2, 1, 2 };
int move_y[8] = { -1, -2, 1, 2, -2, -1, 2, 1 };
using namespace std;
int l = 0; // length of gameboard
int curx, tarx, cury, tary; // x1, y1 : current cordinate of knight  x2, y2 : target cordinate of knight
int c;

//알고리즘 >> x1 y1좌표를 기준으로 gameboard[][] 트리에서 bfs를 시행한다

void solve(int y, int x) {
	visited[y][x] = true;
	queue<pair<pair< int, int >, int>> q;
	q.push(make_pair(make_pair(y, x), 0));
	while (!q.empty()) {
		if (q.front().first.first == tary && q.front().first.second == tarx) {//만약 이동하려는 좌표가 목표 지점과 같다면 현재 이동한 값을 반환하며 탐색을 종료한다.
			c = q.front().second;
			return;
		}
		for (int i = 0; i < 8; ++i) {
			int temp_x, temp_y, temp_num; //나이트가 이동할 좌표 설정
			temp_y = q.front().first.first + move_y[i];
			temp_x = q.front().first.second + move_x[i];
			temp_num = q.front().second;

			if (temp_y >= 0 && temp_y < l && temp_x >= 0 && temp_x < l) { //체스판의 범위를 벗어나지 않는 경우
				if (visited[temp_y][temp_x] == false) {
					visited[temp_y][temp_x] = true;
					q.push(make_pair(make_pair(temp_y, temp_x), temp_num + 1));
				}
			}
		}
		q.pop();
	}
}

int main(void) {
	int t = 0; //number of task cases
	cin >> t;
	while (t--) {
		memset(gameboard, 0, sizeof(gameboard));
		memset(visited, 0, sizeof(visited));
		cin >> l >> cury >> curx >> tary >> tarx;
		c = 0;
		solve(cury, curx);
		cout << c << endl;
	}

	return 0;
}