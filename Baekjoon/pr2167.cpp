#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<vector<int>> vec;
  int N, M;
  cin >> N >> M;

  vec.resize(N + 1);
  for(int i = 0; i < N; i++){
    vec[i].resize(M + 1);
    for(int j = 0; j < M; j++){
      cin >> vec[i][j];
    }
  }

  int tc;
  cin >> tc;
  int i, j, x, y;
  while(tc--){
    cin >> i >> j >> x >> y;
    long long sum = 0;
    for(int k = i; k <= x; k++){
      for(int l = j; l <= y; l++){
        sum += vec[k - 1][l - 1];
      }
    }

    cout << sum << '\n';
  }

  return 0;
}