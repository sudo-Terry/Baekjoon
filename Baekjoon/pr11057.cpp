#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1010

// dp[n][k] -> n자리 숫자, 맨 앞 숫자가 k일때 오르막 수

// dp[n][1] = dp[n-1][1] + ... + dp[n-1][9]
// dp[n][2] = dp[n-1][2] + ... + dp[n-1][9]
// dp[n][k] = dp[n-1][k] + ... + dp[n-1][9]
// dp[1][0] ~ dp[1][9] = 1

int dp[MAX][MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  for(int i = 0; i <= 9; i++){
    dp[1][i] = 1;
  }

  for(int i = 2; i <= N; i++){
    for(int j = 0; j <= 9; j++){
      for(int k = j; k <= 9; k++){
        dp[i][j] += dp[i-1][k];
      }
      dp[i][j] %= 10007;
    }
  }

  long long ans = 0;
  for(int i = 0; i <= 9; i++){
    ans += dp[N][i];
  }
  cout << ans % 10007;

  return 0;
}