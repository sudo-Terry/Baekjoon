#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 증가하는 부분 수열의 최대 길이
int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> child(N), dp(N, 1);
  for (int i = 0; i < N; i++) {
    cin >> child[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (child[j] < child[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int max_val = 0;
  for(size_t i = 0; i < dp.size(); i++){
    max_val = max(dp[i], max_val);
  }
  cout << N - max_val;

  return 0;
}

