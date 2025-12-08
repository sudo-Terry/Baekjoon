#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int dx[] = {-1, 0, 1}; // 0 1 2
int dy[] = {1, 1, 1};
int val_sum = 0;
int N, M;
int min_val = INF;
vector<vector<int>> matrix;

void dfs(int x, int y, int before_move){
  val_sum += matrix[y][x];
  // 달 도착
  if(y == N){
    min_val = min(min_val, val_sum);
  }

  for(int i = 0; i < 3; i++){
    if(before_move == i) continue; // 연속으로 같은 방향 이동은 불가능

    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && ny >= 0 && nx < M && ny <= N){
      dfs(nx, ny, i);
    }
  }

  val_sum -= matrix[y][x];
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;
  matrix.resize(N + 1);
  for(int j = 0; j < M; j++){
    matrix[0].resize(M);
    matrix[0][j] = 0;
  }
  for(int i = 1; i < N + 1; i++){
    matrix[i].resize(M);
    for(int j = 0; j < M; j++){
      int val;
      cin >> val;
      matrix[i][j] = val;
    }
  }

  for(int j = 0; j < M; j++){
    dfs(j, 0, 3);
  }

  cout << min_val;

  return 0;
}