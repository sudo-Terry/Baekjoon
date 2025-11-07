#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 310
#define ICEBERG_MAX 10000
using namespace std;

int n, m;
int ans = 0;
queue<pair<int, int>> q;
int dx[] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[] = {1, -1, 0, 0}; 
bool visited[MAX][MAX];
int arr[MAX][MAX];
int delta[MAX][MAX];
vector<pair<int, int>> iceberg;

bool is_seperated(){
  for(pair<int, int> point : iceberg){
    if (!visited[point.second][point.first] && arr[point.second][point.first] > 0)
      return true;
  }
  return false;
}

void bfs(){
  vector<pair<int,int>> next_iceberg;
  q.push(make_pair(iceberg[0].first, iceberg[0].second));
  visited[iceberg[0].second][iceberg[0].first] = true;
  memset(delta, 0, sizeof(delta));
  
  while (!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    
    for (int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny >= n || nx >= m || nx < 0 || ny < 0) continue;
      
      if (arr[ny][nx] <= 0) delta[y][x]++;
      
      if (arr[ny][nx] > 0 && !visited[ny][nx]){
        q.push(make_pair(nx, ny));
        visited[ny][nx] = true;
      }
    }
  }

  for(pair<int, int> point : iceberg){
    arr[point.second][point.first] -= delta[point.second][point.first];

    if (arr[point.second][point.first] > 0) next_iceberg.push_back(point);
  }

  iceberg.swap(next_iceberg);
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> arr[i][j];
      if (arr[i][j] > 0) iceberg.push_back({j,i});
    }
  }

  while (true){
    memset(visited, false, sizeof(visited));
    if (iceberg.empty()) {
      cout << 0;
      return 0;
    }

    bfs();
    if (is_seperated()){
      cout << ans;
      return 0;
    }
    ans++;
  }
}
