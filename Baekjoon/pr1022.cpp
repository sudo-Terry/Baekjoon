#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 10010

// r: y & c: x
int r1, r2, c1, c2;
/*
우하단 꼭짓점이 (2n+1) ^ 2
한 변의 길이는 2n
*/

int calculate(int col, int row){
  int result;
  int layer = max(abs(row), abs(col));
  int maxVal = (2*layer + 1) * (2*layer + 1);
  
  /*
  하단
  좌변
  우변
  상단
  */
  if (row == layer) result = maxVal - (layer - col);
  else if (col == -layer) result = maxVal - 2 * layer - (layer - row);
  else if (row == -layer) result = maxVal - 4 * layer - (col + layer);
  else result = maxVal - 6 * layer - (row + layer);

  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r1 >> c1 >> r2 >> c2;

  int max_length = 0;
  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      int val = calculate(j, i);
      int len = to_string(val).size();
      if (len > max_length) {
        max_length = len;
      }
    }
  }

  for(int i = r1; i <= r2; i++){
    for(int j = c1; j <= c2; j++){
      int val = calculate(j, i);
      for(int k = 0; k < max_length - to_string(val).size(); k++) cout << ' ';
      cout << val << ' ';
    }
    cout << '\n';
  }

  return 0;
}
