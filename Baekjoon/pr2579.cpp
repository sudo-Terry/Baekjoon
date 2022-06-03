#include<iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 310
using namespace std;

int n, height[MAX];
int dp[MAX];

// dp[0] = h[0]
// dp[1] = h[1] + h[0]
// dp[2] = MAX(h[2] + h[1], h[2] + h[0])
// dp[3] = MAX(h[3] + h[2] + dp[0], h[3] + dp[1])
// dp[n] = MAX(h[n] + h[n-1] + dp[n-3], h[n] + dp[n-2])

void solve() {
  dp[0] = height[0];
  dp[1] = height[1] + height[0];
  dp[2] = max(height[2] + height[0], height[2] + height[1]);
  
  
  for (int i = 3; i < n; i++) {    
    dp[i] = max(height[i] + dp[i-2], height[i] + height[i-1] + dp[i-3]);
  } 
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {   
    cin >> height[i];
  } 
  
  solve();
  
  cout << dp[n - 1] << '\n';   

  return 0;
}