#include <iostream>
#include <vector>
using namespace std;
#define SIZE 9
#define EMPTY 0

int matrix[SIZE][SIZE];
int empty_count = 0;
int cnt = 0;

bool check(int row, int col, int val){
  // 가로 확인
  for(int i = 0 ; i < SIZE; i++) if(matrix[row][i] == val) return false;
  // 세로 확인
  for(int i = 0 ; i < SIZE; i++) if(matrix[i][col] == val) return false;

  // 셀 확인
  for(int i = (row - (row % 3)); i < (row - (row % 3)) + 3; i++){
    for(int j = (col - (col % 3)); j < (col - (col % 3)) + 3; j++){
      if(matrix[i][j] == val) return false;
    }
  }

  return true;
}

void backtrack(int r, int c){
  if(cnt == empty_count){
    for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
        cout << matrix[i][j] << ' ';
      }
      cout << '\n';
    }
    exit(0);
  }

  // 다음 좌표 계산
  int next_r = r;
  int next_c = c + 1;
  if(next_c == SIZE){
    next_r++;
    next_c = 0;
  }

  if(matrix[r][c] == EMPTY){
    for(int i = 1; i <= SIZE; i++){
      if(!check(r, c, i)) continue;

      matrix[r][c] = i;
      cnt++;
      backtrack(next_r, next_c);
      cnt--;
      matrix[r][c] = EMPTY;
    }
  }else{
    backtrack(next_r, next_c);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cin >> matrix[i][j];
      if(matrix[i][j] == EMPTY) empty_count++;
    }
  }

  backtrack(0, 0);

  return 0;
}
