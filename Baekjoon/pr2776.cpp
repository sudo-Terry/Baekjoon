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
    vector<int> guess(M);
    for(int i = 0; i < M; i++) cin >> guess[i];

    sort(vec.begin(), vec.end());

    for(int i = 0; i < M; i++){
      int target = guess[i];

      if (binary_search(vec.begin(), vec.end(), target)) {
        cout << '1' << '\n';
      } else {
        cout << '0' << '\n';
      }
    }
  }

  return 0;
}