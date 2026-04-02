#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 51
#define WALL 1
#define DIRTY 0

/* 
d가 
0인 경우 북쪽, 
1인 경우 동쪽, 
2인 경우 남쪽, 
3인 경우 서쪽
*/

/*
현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
- 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
- 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
- 반시계 방향으로 90도 회전한다.
- 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
*/

int N, M;
int r, c, d;
int ans = 0;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int row, int col){
  queue<pair<int, int>> q;
  q.push({row, col});
  ans++;
  visited[row][col] = true;

  while(!q.empty()){
    int q_size = q.size();
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    bool dirty_exists = false;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      // 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
      if(matrix[ny][nx] == DIRTY && !visited[ny][nx]) dirty_exists = true;
    }

    if(dirty_exists){ // 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
      while(q.empty()){
        d--; // 반시계 방향회전
        if(d < 0) d = 3; // 북 -> 서 overflow

        // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다
        int ny = y + dy[d];
        int nx = x + dx[d];

        if(matrix[ny][nx] == DIRTY && !visited[ny][nx]){
          q.push({ny, nx});
          ans++;
          visited[ny][nx] = true;
        }
      }
    }else{ // 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
      int d_back;
      if(d <= 1) d_back = d + 2;
      else d_back = d - 2;

      int ny = y + dy[d_back];
      int nx = x + dx[d_back];

      if(matrix[ny][nx] == DIRTY){ // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
        q.push({ny, nx});
        if(!visited[ny][nx]) ans++;
        visited[ny][nx] = true;
      }else if(matrix[ny][nx] == WALL){ // 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
        return;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  cin >> r >> c >> d;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> matrix[i][j];
    }
  }

  bfs(r, c);

  cout << ans;

  return 0;
}