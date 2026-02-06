#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> S(N);
  for(int i = 0; i < N; i++) cin >> S[i];

  int left = 0;
  int odd = 0;
  int sum = 0, ans = 0;

  for (int right = 0; right < N; right++) {
    if (S[right] % 2 == 1) odd++;

    while (odd > K) {
      if (S[left] % 2 == 1) odd--;
      left++;
    }

    // 현재 구간에서 짝수 개수
    ans = max(ans, right - left + 1 - odd); 
  }

  cout << ans;

  return 0;
}