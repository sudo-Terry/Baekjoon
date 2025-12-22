#include <iostream>
#define MAX 1010
using namespace std;

int matrix[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0}; // 좌 우 하
int dy[] = {0, 0, 1};
int N, M;
int max_sum = 0;
int sum = 0;

void dfs(int col, int row){
  visited[col][row] = true;
  sum += matrix[col][row];

  if( col == N - 1 && row == M - 1){
    max_sum = max(sum, max_sum);
  }

  for(int i = 0; i < 3; i ++){
    int ny = col + dy[i];
    int nx = row + dx[i];

    if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;

    if(!visited[ny][nx]){
      dfs(ny, nx);
    }
  }

  visited[col][row] = false;
  sum -= matrix[col][row];
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> matrix[i][j];
    }
  }

  dfs(0, 0);

  cout << max_sum;

  return 0;
}