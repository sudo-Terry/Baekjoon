#include <iostream>
using namespace std;

int R, C;
char matrix[20][20];
bool alphabet_visited[26] = {false,};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int max_depth = 0;
int depth = 0;

void dfs(int row, int col){
  alphabet_visited[matrix[col][row] - 'A'] = true;
  depth++;

  if(depth > max_depth) max_depth = depth;

  for(int i = 0; i < 4; i++){
    int x = row + dx[i];
    int y = col + dy[i];
    if(x >= 0 && y >= 0 && x < C && y < R && !alphabet_visited[matrix[y][x] - 'A']){
      dfs(x, y);

      //백트래킹
      depth--;
      alphabet_visited[matrix[y][x] - 'A'] = false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> C;
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      cin >> matrix[i][j];
    }
  }

  dfs(0, 0);

  cout << max_depth;

  return 0;
}