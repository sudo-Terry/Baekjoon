#include <iostream>
#include <vector>
#include <queue>
#define MAX 1010
#define MOVEABLE 0
#define WALL 1
#define NOT_BROKEN 0
#define BROKEN 1
using namespace std;

// 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

int N, M;
bool matrix[MAX][MAX];
bool visited[MAX][MAX][2];
int dx[] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[] = {1, -1, 0, 0};
int depth = 0;

int bfs(int y, int x){
  queue<pair<pair<int, int>, int>> q;
  q.push({{y, x}, 0});
  visited[y][x][0] = true;

  while(!q.empty()){
    int q_size = q.size();
    depth++;

    while(q_size--){
      int cur_y = q.front().first.first;
      int cur_x = q.front().first.second;
      int broke = q.front().second;
      q.pop();

      if(cur_y == N && cur_x == M){
        return depth;
      }
      
      for(int i = 0; i < 4; i++){
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];

        if(ny < 1 || nx < 1 || ny > N || nx > M) continue;

        if(broke){
          if(!visited[ny][nx][BROKEN] && matrix[ny][nx] != WALL){
            visited[ny][nx][BROKEN] = true;
            q.push({{ny, nx}, BROKEN});
          }
        }else{
          if(!visited[ny][nx][NOT_BROKEN]){
            if(matrix[ny][nx] == WALL){
              visited[ny][nx][BROKEN] = true;
              q.push({{ny, nx}, BROKEN});
            }else{
              visited[ny][nx][NOT_BROKEN] = true;
              q.push({{ny, nx}, NOT_BROKEN});
            }
          }
        }
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    string temp;
    cin >> temp;
    for(int j = 1; j <= M; j++){
      matrix[i][j] = (temp[j - 1] == '1');
    }
  }

  cout << bfs(1, 1);

  return 0;
}