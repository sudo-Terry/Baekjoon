#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 110
#define DPMAX 100010

int N, K;
int weight[MAX];
int value[MAX];
int dp[DPMAX]; // dp[i] 가방 무게 i일때 가치 최댓값

void solve(){
  dp[0] = 0;

  for(int j = 0; j < N; j++){ // 모든 물건들에 대해
    for (int i = K; i >= weight[j]; i--) { // 현재 물건을 넣는게 더 크면 갱신
      if (i >= weight[j]) dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> K;
  memset(weight, 0, sizeof(weight));
  memset(value, 0, sizeof(value));

  for(int i = 0; i < N; i++){
    cin >> weight[i] >> value[i];
  }

  solve();

  cout << dp[K] << endl;

  return 0;
}