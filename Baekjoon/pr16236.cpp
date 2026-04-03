#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 30
#define EMPTY 0
#define CUR_POS 9

// 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
int N;
bool visited[MAX][MAX];
int matrix[MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
pair<int, int> shark;
int shark_size = 2;
int shark_ate = 0;
bool flag = true;
int ans = 0;

void bfs(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visited[i][j] = false;
    }
  }

  queue<pair<int,int>> q;
  q.push(shark);
  visited[shark.first][shark.second] = true;
  int cnt = 0;

  while(!q.empty()){
    int q_size = q.size();
    cnt++;
    vector<pair<int,int>> targets;
    for(int i = 0; i < q_size; i++){
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for(int j = 0; j < 4; j++){
        int ny = y + dy[j];
        int nx = x + dx[j];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

        if(!visited[ny][nx] && matrix[ny][nx] <= shark_size ){
          visited[ny][nx] = true;
          q.push({ny, nx});
          
          if(matrix[ny][nx] < shark_size && matrix[ny][nx] > 0){
            targets.push_back({ny, nx});
          }
        }
      }
    }

    if(!targets.empty()){
      sort(targets.begin(), targets.end());
      
      int target_y = targets[0].first;
      int target_x = targets[0].second;

      shark_ate++;
      matrix[target_y][target_x] = EMPTY;
      shark = {target_y, target_x};
      ans += cnt;
      
      if(shark_ate == shark_size){
        shark_size++;
        shark_ate = 0;
      }
      
      return;
    }
  }

  flag = false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> matrix[i][j];
      if(matrix[i][j] == CUR_POS) {
        shark = {i, j};
        matrix[i][j] = EMPTY;
      };
    }
  }

  while(true){
    bfs();

    if(!flag) break; // 먹은게 없다
  }

  cout << ans << '\n';

  // for(int i = 0; i < N; i++){
  //   for(int j = 0; j < N; j++){
  //     cout << matrix[i][j] << ' '; 
  //   }
  //   cout << '\n';
  // }

  return 0;
}