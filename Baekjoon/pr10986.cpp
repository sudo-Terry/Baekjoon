#include <iostream>
#include <vector>
using namespace std;

/*
0 ~ i 까지 누적합의 나머지
j ~ i 누적합의 나머지
나머지가 같은 구간을 조합으로 2개 선택
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<long long> count(M, 0); 
  long long sum = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
      long long A;
      cin >> A;
      
      sum = (sum + A) % M;
      count[sum]++;
  }

  ans += count[0];

  for (int i = 0; i < M; i++) {
    if (count[i] > 1) {
      ans += (count[i] * (count[i] - 1)) / 2;
    }
  }

  cout << ans;

  return 0;
}