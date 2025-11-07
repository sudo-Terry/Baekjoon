#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1010

int matrix[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {1, -1, 0, 0};
int n, m;

void bfs(int x, int y){
  queue<pair<int, int>> q;
  
  q.push(make_pair(x, y));
  int counter = 0;
  while(!q.empty()){
    int q_size = q.size();
    while(q_size--){
      int ty = q.front().second;
      int tx = q.front().first;
      q.pop();
      dist[ty][tx] = counter;
      
      for(int i = 0; i < 4; i++){
        int ny = ty + dy[i];
        int nx = tx + dx[i];
        if(!visited[ny][nx] && matrix[ny][nx] == 1 && ny >= 0 && nx >= 0 && ny < n && nx <m){
          q.push(make_pair(nx, ny));
          visited[ny][nx] = true;
        }
      }
    }
    counter++;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int rootNode;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ 
      cin >> matrix[i][j];

      if(matrix[i][j] == 2) rootNode = i * MAX + j;
      if(matrix[i][j] == 0) dist[i][j] = 0;
    }
  }

  bfs(rootNode % MAX, rootNode / MAX);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){ 
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}