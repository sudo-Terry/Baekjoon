#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  vector<int> vec;
  cin >> N >> K;
  vec.resize(N);
  for(int i = 0; i < N; i++) cin >> vec[i];

  int left = 0;
  int right = K - 1;
  int ans = 0;
  int sum = 0;
  for(int i = left; i <= right; i++) sum += vec[i];
  ans = sum;
  while(right < N - 1){
    sum -= vec[left];
    left++; right++;
    sum += vec[right];

    ans = max(sum, ans);
  }

  cout << ans;

  return 0;
}