#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int H, W;
  cin >> H >> W;

  vector<int> block(W);
  for (int i = 0; i < W; i++) {
    cin >> block[i];
  }

  vector<int> left_max(W), right_max(W);

  left_max[0] = block[0];
  for (int i = 1; i < W; i++) {
    left_max[i] = max(left_max[i - 1], block[i]);
  }

  right_max[W - 1] = block[W - 1];
  for (int i = W - 2; i >= 0; i--) {
    right_max[i] = max(right_max[i + 1], block[i]);
  }

  int ans = 0;
  for (int i = 0; i < W; i++) {
    int water = min(left_max[i], right_max[i]) - block[i];
    if (water > 0) ans += water;
  }

  cout << ans << '\n';

  return 0;
}