#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;

  cin >> N;
  bool is_prime[N + 1];

  memset(is_prime, true, sizeof(is_prime));
  is_prime[1] = false;

  // 에라토스테네스의 체 알고리즘
  for (int i = 2; i <= sqrt(N); i++) {
    if (!is_prime[i]) continue;
    for (int j = 2; i * j <= N; j++) is_prime[i * j] = false;
  }

  int left = 2;
  int right = 2;
  int sum = 2;
  int ans = 0;
  while(true){
    if(N == sum) ans++;

    if(N >= sum){
      while(1){
        right++;
        if(right > N) {
          cout << ans;
          return 0;
        }
        if(is_prime[right]) break;
      }
      //cout << "right: " << right << endl;
      sum += right;
    }else{
      int temp = left;
      while(1){
        left++;
        if(is_prime[left]) break;
      }
      //cout << "left: " << left << endl;
      sum -= temp;
    }
  }

  cout << ans;

  return 0;
}