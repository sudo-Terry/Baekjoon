#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 110
#define ROTTEN 1
#define CLEAN 0
#define EMPTY -1

int M, N, H;
int matrix[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dx[6] = { 1, -1, 0, 0, 0, 0};
int dy[6] = { 0, 0, 1, -1, 0, 0};
int dz[6] = { 0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> rotten_pos;

// 1은 익은 토마토
// 0 은 익지 않은 토마토
// -1은 토마토가 들어있지 않은 칸
// 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력

void bfs_once(){
  int q_size = rotten_pos.size();
  for(int i = 0; i < q_size; i++){
    auto [x, y, z] = rotten_pos.front();
    rotten_pos.pop();

    for(int j = 0; j < 6; j++){
      int nx = x + dx[j];
      int ny = y + dy[j];
      int nz = z + dz[j];

      if(nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;

      if(matrix[nx][ny][nz] == CLEAN && !visited[nx][ny][nz]){
        matrix[nx][ny][nz] = ROTTEN;
        rotten_pos.push({nx, ny, nz});
        visited[nx][ny][nz] = true;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  bool flag = false;
  cin >> M >> N >> H;
  for(int k = 0; k < H; k++){
    for(int j = 0; j < N; j++){
      for(int i = 0; i < M; i++){
        cin >> matrix[i][j][k];

        // 안익은 토마토가 존재
        if(matrix[i][j][k] == CLEAN) flag = true;
        if(matrix[i][j][k] == ROTTEN) {
          rotten_pos.push({i, j, k});
          visited[i][j][k] = true;
        }
      }
    }
  }

  if(!flag){ // 모든 토마토가 익어있는 상태
    cout << "0";
    return 0;
  }

  int count = -1;
  while(!rotten_pos.empty()){
    // cout << rotten_pos.size() << endl;
    bfs_once();
    count++;
  }

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < H; k++){
        if(matrix[i][j][k] == CLEAN){
          cout << "-1";
          return 0;
        }
      }
    }
  }

  cout << count;

  return 0;
}