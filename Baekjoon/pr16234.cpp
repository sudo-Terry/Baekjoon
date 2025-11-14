#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 55

int N, L, R;
vector<vector<int>> matrix;
bool visited[MAX][MAX];
int dx[] = {0, 0, -1, 1}; // 상하좌우
int dy[] = {1, -1, 0, 0};

bool bfs(int col, int row){
  if(visited[col][row]) return false;

  queue<pair<int, int>> q;
  vector<pair<int, int>> adj_list;
  q.push({col, row});
  adj_list.push_back({col, row});
  visited[col][row] = true;
  int pop_sum = 0;
  int count = 0;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    pop_sum += matrix[y][x];
    count++;
    q.pop();

    for(int k = 0; k < 4; k++){
      int nx = x + dx[k];
      int ny = y + dy[k];
      if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[ny][nx]){
        if(abs(matrix[y][x] - matrix[ny][nx]) >= L && abs(matrix[y][x] - matrix[ny][nx]) <= R){
          visited[ny][nx] = true;
          q.push({ny, nx});
          adj_list.push_back({ny, nx});
        }
      }
    }
  }

  if(adj_list.size() == 1) return false;

  for(auto cor : adj_list){
    matrix[cor.first][cor.second] = (int)(pop_sum / count);
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> L >> R;
  matrix.resize(N+1);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int population;
      cin >> population;
      matrix[i].push_back(population);
    }
  }

  int counter = 0;
  while(true){
    bool flag = false;
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(bfs(i, j)) flag = true;
      }
    }

    if(!flag) break;
    counter++;
  }

  cout << counter;

  return 0;
}