#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WALL 6

vector<vector<int>> matrix;
vector<pair<int, int>> cctvs; 
int N, M;
int min_ans = 1000000000;

int count(vector<vector<int>> &current_map){
  int counter = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if (current_map[i][j] == 0) counter++;
    }
  }

  return counter;
}

vector<vector<int>> x_right(int col, int row, vector<vector<int>> temp_matrix){
  int n_row = row;
  while(n_row < M && temp_matrix[col][n_row] != WALL){
    temp_matrix[col][n_row] = -1;
    n_row++;
  }
  return temp_matrix;
}

vector<vector<int>> x_left(int col, int row, vector<vector<int>> temp_matrix){
  int n_row = row;
  while( n_row >= 0 && temp_matrix[col][n_row] != WALL){
    temp_matrix[col][n_row] = -1;
    n_row--;
  }
  return temp_matrix;
}

vector<vector<int>> y_top(int col, int row, vector<vector<int>> temp_matrix){
  int n_col = col;
  while( n_col < N && temp_matrix[n_col][row] != WALL){
    temp_matrix[n_col][row] = -1;
    n_col++;
  }
  return temp_matrix;
}

vector<vector<int>> y_bot(int col, int row, vector<vector<int>> temp_matrix){
  int n_col = col;
  while(n_col >= 0 && temp_matrix[n_col][row] != WALL){
    temp_matrix[n_col][row] = -1;
    n_col--;
  }
  return temp_matrix;
}

void dfs(int idx, vector<vector<int>> current_map) {
  if (idx == cctvs.size()) {
    int cnt = count(current_map);
    if (cnt < min_ans) min_ans = cnt;
    return;
  }

  int r = cctvs[idx].first;
  int c = cctvs[idx].second;
  int type = matrix[r][c];

  if (type == 1) {
    dfs(idx + 1, x_right(r, c, current_map));
    dfs(idx + 1, x_left(r, c, current_map));
    dfs(idx + 1, y_top(r, c, current_map));
    dfs(idx + 1, y_bot(r, c, current_map));
  } 
  else if (type == 2) {
    dfs(idx + 1, x_right(r, c, x_left(r, c, current_map)));
    dfs(idx + 1, y_top(r, c, y_bot(r, c, current_map)));
  } 
  else if (type == 3) {
    dfs(idx + 1, y_bot(r, c, x_right(r, c, current_map)));
    dfs(idx + 1, x_right(r, c, y_top(r, c, current_map)));
    dfs(idx + 1, y_top(r, c, x_left(r, c, current_map)));
    dfs(idx + 1, x_left(r, c, y_bot(r, c, current_map)));
  } 
  else if (type == 4) {
    dfs(idx + 1, y_bot(r, c, x_right(r, c, y_top(r, c, current_map))));
    dfs(idx + 1, x_right(r, c, y_top(r, c, x_left(r, c, current_map))));
    dfs(idx + 1, y_top(r, c, x_left(r, c, y_bot(r, c, current_map))));
    dfs(idx + 1, x_left(r, c, y_bot(r, c, x_right(r, c, current_map))));
  } 
  else if (type == 5) {
    dfs(idx + 1, x_right(r, c, x_left(r, c, y_top(r, c, y_bot(r, c, current_map)))));
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;
  matrix.resize(N);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      int temp;
      cin >> temp;
      matrix[i].push_back(temp);
      if(temp >= 1 && temp <= 5) {
        cctvs.push_back({i, j});
      }
    }
  }

  dfs(0, matrix);

  cout << min_ans;

  return 0;
}