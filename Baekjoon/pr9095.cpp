#include <iostream>
#include <vector>
using namespace std;
#define MAX 11

/*
마지막에 1을 붙였다면 -> (n-1)을 만드는 모든 경우
마지막에 2를 붙였다면 -> (n-2)을 만드는 모든 경우
마지막에 3을 붙였다면 -> (n-3)을 만드는 모든 경우
dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
dp[1] = 1
dp[2] = 2
dp[3] = 4
dp[4] = 7
*/

int T;
int dp[MAX];
vector<int> arr;

void dfs() {
  if (arr.size() == M) {
    for (int x : arr) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    arr.push_back(i);
    dfs();
    arr.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;
  int n;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 7;
  for(int i = 5; i <= 10; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  while(T--){
    cin >> n;
    cout << dp[n] << '\n';
  }

  return 0;
}