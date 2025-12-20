#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1010
#define WALL 1
#define EMPTY 0
using namespace std;

int matrix[MAX][MAX];
int visited[MAX][MAX];
int fire_visited[MAX][MAX];
int dx[] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> fire_q;
int R, C;

void print_matrix(){
  for(int i = 1 ; i <= R; i++){
    for(int j = 1 ; j <= C; j++){
      cout << matrix[i][j];
    }
    cout << '\n';
  }
}

void bfs(int r, int c){
  queue<pair<int, int>> q;
  visited[r][c] = true;
  q.push({r, c});
  int counter = 0;

  while(!q.empty()){
    int q_size = q.size();
    int fire_q_size= fire_q.size();
    counter++;
    // print_matrix();

    for(int i = 0; i < fire_q_size; i++){
      int y = fire_q.front().first;
      int x = fire_q.front().second;
      fire_q.pop();

      for(int j = 0; j < 4; j++){
        int nx = x + dx[j];
        int ny = y + dy[j];

        if(ny == 0 || nx == 0 || ny == R + 1 || nx == C + 1) continue;

        if(matrix[ny][nx] == EMPTY && !fire_visited[ny][nx]){
          fire_visited[ny][nx] = true;
          fire_q.push({ny, nx});
          matrix[ny][nx] = WALL;
        }
      }
    }

    for(int i = 0; i < q_size; i++){
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for(int j = 0; j < 4; j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        
        if((ny == 0 || nx == 0 || ny == R + 1 || nx == C + 1) && matrix[ny][nx] == EMPTY) {
          // cout << nx << ' ' << ny << endl;
          cout << counter;
          return;
        }

        if(matrix[ny][nx] == EMPTY && !visited[ny][nx]){
          visited[ny][nx] = true;
          q.push({ny, nx});
        }
      }
    }
  }

  cout << "IMPOSSIBLE";
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> R >> C;
  int start_r, start_c;
  for(int i = 1 ; i <= R; i++){
    for(int j = 1 ; j <= C; j++){
      char temp;
      cin >> temp;

      if(temp == 'J'){
        start_r = i;
        start_c = j;
        matrix[i][j] = EMPTY;
      }else if(temp =='F'){
        fire_visited[i][j] = true;
        fire_q.push({i, j});
        matrix[i][j] = WALL;
      }else if(temp == '.'){
        matrix[i][j] = EMPTY;
      }else if(temp == '#'){
        matrix[i][j] = WALL;
      }
    }
  }

  bfs(start_r, start_c);

  return 0;
}