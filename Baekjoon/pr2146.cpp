#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 101
#define SEA 0
#define LAND 1
#define INF 987654321

int N;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<queue<pair<int, int>>> edges;
int ans = INF;

void dfs(int col, int row, int area_num){
  visited[col][row] = true;
  matrix[col][row] = area_num;

  for(int i = 0; i < 4; i++){
    bool edge_flag = true;
    int n_col = col + dy[i];
    int n_row = row + dx[i];
    
    if(n_col < 0 || n_col >= N || n_row < 0 || n_row >= N) continue;

    if(matrix[n_col][n_row] == SEA) edge_flag = true;

    if(matrix[n_col][n_row] == LAND && !visited[n_col][n_row]){
      dfs(n_col, n_row, area_num);
    }

    if(edge_flag) edges[area_num].push({col, row});
  }
}

void bfs(int area_num){
  bool bfs_visited[N][N];
  memset(bfs_visited, false, sizeof(bfs_visited));
  queue<pair<int, int>> q = edges[area_num];
  int depth = 1;

  while(!q.empty()){
    int q_size = q.size();
    for(int i = 0; i < q_size; i++){
      int col = q.front().first;
      int row = q.front().second;
      bfs_visited[col][row] = true;
      q.pop();

      for(int j = 0; j < 4; j++){
        int n_col = col + dy[j];
        int n_row = row + dx[j];

        if(n_col < 0 || n_col >= N || n_row < 0 || n_row >= N) continue;

        if(matrix[n_col][n_row] == SEA && !bfs_visited[n_col][n_row]){
          bfs_visited[n_col][n_row] = true;
          q.push({n_col, n_row});
        }else if(matrix[n_col][n_row] != SEA && matrix[n_col][n_row] != area_num){
          ans = min(ans, depth - 1);
          return;
        }
      }
    }
    depth++;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  edges.resize(N * N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> matrix[i][j];
    }
  }

  int area_counter = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(matrix[i][j] == LAND && !visited[i][j]) dfs(i, j ,area_counter++);
    }
  }

  for(int i = 1; i < area_counter; i++){
    bfs(i);
  }

  cout << ans;

  return 0;
}