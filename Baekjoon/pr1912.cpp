#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX 100010

/*
dp[n]: n으로 끝나는 최대 연속합
dp[n] = max(dp[n - 1] + vec[n], vec[n])
*/

int n;
vector<int> vec;
int dp[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }
  dp[0] = vec[0];
  for(int i = 1; i < n; i++){
    dp[i] = max(dp[i - 1] + vec[i], vec[i]);
  }
  int ans = INT_MIN;
  for(int i = 0; i < n; i++){
    ans = max(dp[i], ans);
  }

  cout << ans;

  return 0;
}