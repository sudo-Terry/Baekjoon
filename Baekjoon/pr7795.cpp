#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  
  while(T--){
    cin >> N >> M;
    vector<int> A, B;

    for(int i = 0; i < N; i++){
      int temp;
      cin >> temp;
      A.push_back(temp);
    }
    for(int i = 0; i < M; i++){
      int temp;
      cin >> temp;
      B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    int idx_b = 0;
    for(int i = 0; i < N; i++){
      // A는 자기보다 크기가 작은 먹이만 먹을 수 있다
      while(idx_b < M && A[i] > B[idx_b]){
        idx_b++;
      }

      ans += idx_b;
    }

    cout << ans << '\n';
  }

  return 0;
}