#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1010

int pillar[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;

  int max_height = 0;
  int max_pos = 0, left_pos = 10000, right_pos = 0;
  int ans = 0;
  while(N--){
    int pos, height;
    cin >> pos >> height;

    right_pos = max(pos, right_pos);
    left_pos = min(pos, left_pos);
    if(height > max_height) max_pos = pos;
    max_height = max(height, max_height);

    pillar[pos] = height;
  }
  
  // left
  int left_max_height = 0;
  for(int i = left_pos; i < max_pos; i++){
    left_max_height = max(left_max_height, pillar[i]);
    ans += left_max_height;
  }

  ans += max_height;

  // right
  int right_max_height = 0;
  for(int i = right_pos; i > max_pos; i--){
    right_max_height = max(right_max_height, pillar[i]);
    ans += right_max_height;
  }

  cout << ans << '\n';

  return 0;
}