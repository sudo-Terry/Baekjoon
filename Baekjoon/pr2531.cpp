#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, d, k, c;
  cin >> N >> d >> k >> c;
  vector<int> sushies(N);
  vector<int> sushi_count(d + 1, 0);
  for(int i = 0; i < N; i++) cin >> sushies[i];
  for(int i = 0; i < k; i++) sushies.push_back(sushies[i]);

  int left = 0, ans = 0;
  int right = k - 1;
  int sushi_types = 1;
  sushi_count[c]++;

  // 0 ~ 
  for(int right = 0; right < sushies.size(); right++){
    if(right - left == k){ // 윈도우 왼쪽 이동
      sushi_count[sushies[left]]--;
      if(sushi_count[sushies[left]] == 0) sushi_types--;
      left++;
    }
    // 윈도우 오른쪽 처리
    if(sushi_count[sushies[right]] == 0) sushi_types++;
    sushi_count[sushies[right]]++;

    ans = max(ans, sushi_types);
  }

  cout << ans;

  return 0;
}