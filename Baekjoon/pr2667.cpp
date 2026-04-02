#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 30

int N;
bool matrix[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> size_vec;

void bfs(int row, int col){
  int count = 1;
  queue<pair<int, int>> q;
  visited[row][col] = true;
  q.push({row, col});

  while(!q.empty()){
    int q_size = q.size();
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

      if(matrix[ny][nx] && !visited[ny][nx]){
        visited[ny][nx] = true;
        q.push({ny, nx});
        count++;
      }
    }
  }

  size_vec.push_back(count);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
    for(int j = 0; j < N; j++){
      matrix[i][j] = (s[j] == '1');
    }
  }

  int group_count = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(matrix[i][j] && !visited[i][j]) {
        group_count++;
        bfs(i, j);
      }
    }
  }

  sort(size_vec.begin(), size_vec.end());
  cout << group_count << '\n';
  for(size_t i = 0; i < size_vec.size(); i++) cout << size_vec[i] << '\n';

  return 0;
}