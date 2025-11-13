#include <iostream>
#include <vector>
using namespace std;
#define MAX 1010

int N;
bool matrix[MAX][MAX];
int top_x, top_y, left_x, left_y, right_x, right_y, bottom_x, bottom_y, bottom_lx, bottom_ly, bottom_rx, bottom_ry;

void search_top(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(matrix[i][j]){
        top_x = j; top_y = i;
        return;
      }
    }
  }
}

void search_left(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(matrix[j][i]){
        left_y = j; left_x = i;
        return;
      }
    }
  }
}

void search_right(){
  for(int i = N - 1; i > 0; i--){
    if(matrix[left_y][i]){
      right_y = left_y; right_x = i;
      return;
    }
  }
}

void search_bottom(){
  for(int i = N - 1; i > 0; i--){
    if(matrix[i][top_x]){
      bottom_x = top_x; bottom_y = i;
      return;
    }
  }
}

void search_bottom_left(){
  for(int i = N - 1; i > bottom_y; i--){
    if(matrix[i][top_x - 1]){
      bottom_lx = top_x; bottom_ly = i;
      return;
    }
  }
}

void search_bottom_right(){
  for(int i = N - 1; i > bottom_y; i--){
    if(matrix[i][top_x + 1]){
      bottom_rx = top_x; bottom_ry = i;
      return;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      char temp;
      cin >> temp;
      if (temp == '*') matrix[i][j] = true;
      else matrix[i][j] = false;
    }
  }

  search_top();
  search_left();
  search_right();
  search_bottom();
  search_bottom_left();
  search_bottom_right();

  int left_arm = left_x - top_x;
  int right_arm = right_x - top_x;
  int waist = bottom_y - top_y - 1;
  int left_leg = bottom_ly - bottom_y - 1;
  int right_leg = bottom_ry - bottom_y - 1;

  cout << top_x << ' ' << left_y << '\n';
  cout << left_arm << ' ' << right_arm << ' ' << waist << ' ' << left_leg << ' ' << right_leg;

  return 0;
}