#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

/*
. : 빈 공간
# : 벽
@ : 상근이의 시작 위치
* : 불
*/

#define MAX 1010

int tc;
int w, h;
int seconds;
char matrix[MAX][MAX];
int dx[] = { 0, 0, -1, 1}; //상하좌우
int dy[] = { -1, 1, 0, 0};

bool wall[MAX][MAX] = {false,};
bool visited[MAX][MAX] = {false,};
bool fire_visited[MAX][MAX] ={false,};
queue<pair<int, int>> q;
queue<pair<int, int>> fire_q;

void bfs(int y, int x){
  q.push(make_pair(y, x));
  visited[y][x] = true;

  while(!q.empty()){
    // 불 이동
    int fire_q_size = fire_q.size();
    for(int j = 0; j < fire_q_size; j++){
      int current_fire_y = fire_q.front().first;
      int current_fire_x = fire_q.front().second;
      fire_q.pop();

      for (int k = 0; k < 4; k++){
        int ny = current_fire_y + dy[k];
        int nx = current_fire_x + dx[k];

        // 불이 못번짐
        if(ny <=0 || nx <= 0 || ny > h || nx > w) continue;
        
        if(!fire_visited[ny][nx] && !wall[ny][nx]){
          fire_visited[ny][nx] = true;
          fire_q.push(make_pair(ny, nx));
        }
      }
    }

    int size = q.size();
    for(int i = 0; i < size; i++){
      int current_y = q.front().first;
      int current_x = q.front().second;
      q.pop();

      //종료조건일 경우
      if(current_x == 0 || current_x == w + 1  || current_y == 0 || current_y == h+1 ){
        cout << seconds << '\n';
        return;
      }

      // 상근 이동 (불, 벽으로는 불가능)
      for(int j = 0; j < 4; j++){
        int ny = current_y + dy[j];
        int nx = current_x + dx[j];

        if(!wall[ny][nx] && !visited[ny][nx] && !fire_visited[ny][nx]){
          visited[ny][nx] = true;
          q.push(make_pair(ny, nx));
        }
      }
    }
    seconds++;
  }

  cout << "IMPOSSIBLE" << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> tc;
  while(tc--){
    cin >> w >> h;

    seconds = 0;
    while (!q.empty()) q.pop();
    while (!fire_q.empty()) fire_q.pop();
    memset(visited, false, sizeof(visited));
    memset(fire_visited, false, sizeof(fire_visited));
    memset(wall, false, sizeof(wall));

    int start_col, start_row;
    for(int i = 1; i <= h; i++){
      for(int j = 1; j <= w; j++){
        char c;
        cin >> c;
        matrix[i][j] = c;
        
        if(c == '@') {
          start_col = i;
          start_row = j;
        }
        if(c == '*') {
          fire_q.push(make_pair(i, j));
          fire_visited[i][j] = true;
        }
        if(c == '#') wall[i][j] = true;
      }
    }

    bfs(start_col, start_row);
  }

  return 0;
}