#include <iostream>

using namespace std;

int N;
/*
1: 1 상근 승
2: 1 1 창영 승
3: 3 = 상근 승
4: 3 1 / 1 3 = 창영 승
5: 3 1 dp[1] / 1 1 dp[3] / 1 3 dp[1] 상근 승
6: 3 1 dp[2] / 1 3 dp[2] / 1 1 dp[4] 창영 승
7: 1 1 dp[5] / 1 3 dp[3] / 3 1 dp[3] / 3 3 dp[1]
*/

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N;

  if(N%2 == 1) cout << "SK";
  else cout << "CY"; 

  return 0;
}