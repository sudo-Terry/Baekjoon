#include <iostream>
#include <algorithm>
#define MAX 1050

using namespace std;
int n, ans = 0;
int arr[MAX + 1] = {
    0,
};
int dp[MAX + 1] = {
    0,
}; // memoization

// dp[n]은 arr[n]을 포함하는 부분 수열 중, 가장 긴 길이를 가지는 증가하는 부분 수열

void solve()
{
  for (int i = 1; i <= n; i++)
  {
    dp[i] = 1;
    for (int j = 1; j < i; j++)
    {
      if (arr[i] > arr[j])
      {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
}

int main(void)
{

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  solve();

  return 0;
}