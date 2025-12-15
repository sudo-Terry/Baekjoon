#include <iostream>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int H, W, N, M;
  cin >> H >> W >> N >> M;

  int h_count = (H - 1) / (N + 1) + 1;
  int w_count = (W - 1) / (M + 1) + 1;

  cout << (long long)h_count * w_count;

  return 0;
}