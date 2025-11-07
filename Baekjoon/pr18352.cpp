#include <iostream>
#include <vector>
#include <cstring>
#define MAX 510
using namespace std;

int N, M;
bool matrix[MAX][MAX] = {false,};
bool visited[MAX][MAX] = {false,};
int dx[4] = {0, 0, -1, 1}; //상하좌우
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y){
  if(visited[y][x]) return 0;

  int counter = 1;
  visited[y][x] = true;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx >= 0 && ny >= 0 && nx < M && ny < N && matrix[ny][nx]){
      counter += dfs(nx, ny);
    }
  }

  return counter;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int max_image_size = 0;
  int image_num = 0;
  int image_size = 0;

  cin >> N >> M;
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      int temp;
      cin >> temp;
      matrix[i][j] = (temp == 1);
    }
  }

  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      if(visited[i][j] || !matrix[i][j]) continue;

      image_size = dfs(j, i);

      if(image_size > max_image_size) max_image_size = image_size;
      image_num++;
    }
  }

  cout << image_num << '\n' << max_image_size;

  return 0;
}