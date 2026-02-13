#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    cin >> M;
    vector<int> guess;
    for(int i = 0; i < M; i++) cin >> guess[i];

    sort(vec.begin(), vec.end());

    for(int i = 0; i < M; i++){
      int target = guess[i];

      auto lb = lower_bound(vec.begin(), vec.end(), target);
      auto ub = upper_bound(vec.begin(), vec.end(), target);
    }
  }

  return 0;
}