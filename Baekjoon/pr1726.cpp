#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 110

// 동쪽이 1, 서쪽이 2, 남쪽이 3, 북쪽이 4
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4

struct Robot {
  int y, x, dir, count;
};

int M, N;
int matrix[MAX][MAX];
bool visited[MAX][MAX][5];
int dy[] = {0, 0, 0, 1, -1}; 
int dx[] = {0, 1, -1, 0, 0};
int start_y, start_x, start_dir;
int end_y, end_x, end_dir;

int dir_diff(int start_dir, int end_dir){
  if(start_dir == end_dir) return 0;

  if(start_dir == EAST && end_dir == WEST
    || start_dir == NORTH && end_dir == SOUTH
    || start_dir == WEST && end_dir == EAST
    || start_dir == SOUTH && end_dir == NORTH){
    return 2;
  } else{
    return 1;
  }
}

int bfs() {
  queue<Robot> q;
  q.push({start_y, start_x, start_dir, 0});
  visited[start_y][start_x][start_dir] = true;

  while (!q.empty()) {
    Robot cur = q.front();
    q.pop();

    if (cur.y == end_y && cur.x == end_x && cur.dir == end_dir) {
      return cur.count;
    }

    // Go
    for (int k = 1; k <= 3; k++) {
      int ny = cur.y + dy[cur.dir] * k;
      int nx = cur.x + dx[cur.dir] * k;

      if (ny < 1 || nx < 1 || ny > M || nx > N || matrix[ny][nx] == 1) break;

      if (!visited[ny][nx][cur.dir]) {
        visited[ny][nx][cur.dir] = true;
        q.push({ny, nx, cur.dir, cur.count + 1});
      }
    }

    // 회전
    for (int i = 1; i <= 4; i++) {
      int turn_count = dir_diff(cur.dir, i);

      if (!visited[cur.y][cur.x][i]) {
        visited[cur.y][cur.x][i] = true;
        q.push({cur.y, cur.x, i, cur.count + turn_count});
      }
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> M >> N;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> matrix[i][j];
    }
  }
  cin >> start_y >> start_x >> start_dir;
  cin >> end_y >> end_x >> end_dir;

  cout << bfs();

  return 0;
}