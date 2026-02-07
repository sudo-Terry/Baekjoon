#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int ans = 5;
  int left = 0;

  for(int right = 0; right < N; right++){
    while(v[right] - v[left] >= 5){
      left++;
    }
    int cnt = right - left + 1;
    ans = min(ans, 5 - cnt);
  }

  cout << ans;

  return 0;
}