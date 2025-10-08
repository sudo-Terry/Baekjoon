#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 100010

int tc, n;
int sticker[2][MAX];
int dp[MAX][3];

/*
dp[i][j] = i 번째에서 j열의 스티커를 떼었을 경우 가중치 합 최댓값
dp[i+1][0] = max(dp[i][1], dp[i][2])
dp[i+1][1] = max(dp[i][0], dp[i][2]) + sticker[i+1][0]
dp[i+1][2] = max(dp[i][0], dp[i][1]) + sticker[i+1][1]
*/

void solve() {
  dp[1][0] = 0;
  dp[1][1] = sticker[0][1];
  dp[1][2] = sticker[1][1];

  for(int i = 1; i < n; i++){
    dp[i+1][0] = max(dp[i][1], dp[i][2]);
    dp[i+1][1] = max(dp[i][0], dp[i][2]) + sticker[0][i+1];
    dp[i+1][2] = max(dp[i][0], dp[i][1]) + sticker[1][i+1];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> tc;
  while (tc--){

    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 0; i < 2 ; i++){
      for(int j = 1; j <= n; j++){
        cin >> sticker[i][j];
      }
    }
    solve();

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
  }

  return 0;
}