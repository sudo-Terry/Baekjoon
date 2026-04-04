#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fruit_cnt[10];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<int> fruits(N + 1);
  for(int i = 0; i < N; i++) cin >> fruits[i];

  int left = 0;
  int right = 0;
  int fruit_types = 1;
  fruit_cnt[fruits[0]]++;
  int max_len = 1;
  while(right < N){
    // cout << left << ' ' << right << '\n';
    if(fruit_types > 2){
      fruit_cnt[fruits[left]]--;
      if(fruit_cnt[fruits[left]] == 0) {
        fruit_types--;
      }
      left++;
    }else{
      max_len = max(max_len, right - left + 1);

      if(fruit_cnt[fruits[right + 1]] == 0) {
        fruit_types++;
      }
      fruit_cnt[fruits[right + 1]]++;
      right++;
      
    }
  }

  cout << max_len;

  return 0;
}