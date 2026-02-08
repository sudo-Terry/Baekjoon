#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  vector<int> AB, CD;
  vector<int> A(N), B(N), C(N), D(N);

  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      AB.push_back(A[i] + B[j]);
    }
  }
  sort(AB.begin(), AB.end());
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      CD.push_back(C[i] + D[j]);
    }
  }
  sort(CD.begin(), CD.end(), [](const int& a, const int& b){
    return a > b;
  });

  /*
  0 0 -1 -1 -2 -2 -3 -3 -3
  3 3 2 1 0 0 -1
  */
  long long ans = 0;
  int i = 0, j = 0;
  while (i < AB.size() && j < CD.size()) {
    long long sum = AB[i] + CD[j];

    if (sum == 0) {
      int ab_val = AB[i];
      int cd_val = CD[j];

      long long ab_cnt = 0;
      long long cd_cnt = 0;

      while (i < AB.size() && AB[i] == ab_val) {
        ab_cnt++;
        i++;
      }
      while (j < CD.size() && CD[j] == cd_val) {
        cd_cnt++;
        j++;
      }

      ans += ab_cnt * cd_cnt;
    }
    else if (sum < 0) i++;
    else j++;
  }

  cout << ans;

  return 0;
}