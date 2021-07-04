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

//�˰��� >> x1 y1��ǥ�� �������� gameboard[][] Ʈ������ bfs�� �����Ѵ�

void solve(int y, int x) {
	visited[y][x] = true;
	queue<pair<pair< int, int >, int>> q;
	q.push(make_pair(make_pair(y, x), 0));
	while (!q.empty()) {
		if (q.front().first.first == tary && q.front().first.second == tarx) {//���� �̵��Ϸ��� ��ǥ�� ��ǥ ������ ���ٸ� ���� �̵��� ���� ��ȯ�ϸ� Ž���� �����Ѵ�.
			c = q.front().second;
			return;
		}
		for (int i = 0; i < 8; ++i) {
			int temp_x, temp_y, temp_num; //����Ʈ�� �̵��� ��ǥ ����
			temp_y = q.front().first.first + move_y[i];
			temp_x = q.front().first.second + move_x[i];
			temp_num = q.front().second;

			if (temp_y >= 0 && temp_y < l && temp_x >= 0 && temp_x < l) { //ü������ ������ ����� �ʴ� ���
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