#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[n] = dp[n-1] + dp[n % 3] ..?
// 1이 하나 더 추가되는건데 그건 이미 주머니가 3으로 찬거엔 못넣는다
// 1이랑 2로만 이루어진거에서는 새로운 조합을 만들어낼 수 있다?
// dp[7] = dp[6] + dp[1]
//  6 -> 111111 / 33 / 3111 / 321 / 222 / 2211 / 21111
// dp[6] = 7
//  5 -> 11111 / 32 / 311 / 221 / 2111
// dp[5] = 5
//  4 -> 1111 / 31 / 22 / 211 
// dp[4] = 4
//  3 -> 111 / 12 / 3 
// dp[3] = 3
//  2 -> 11 / 2
// dp[2] = 2

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  vector<int> dp(10001, 0);
  dp[0] = 1;

  int coins[3] = {1,2,3};

  for(int c : coins){
    for(int i = c; i <= 10000; i++){
      dp[i] += dp[i - c];
    }
  }

  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }

  return 0;
}