#include <iostream>
using namespace std;

/*
점 하나는 고정으로 선택하고 나머지 2개를 임의의 거리를 가지는 점의 조합으로 선택
거리 2개를 고르면 나머지 거리는 자동 선택된다
합이 N이 되는 숫자 조합 수
회전 -> 3번 겹침
3
1 1 (1)

8
1 1 (6)
1 2 5
1 3 4
1 4 3
1 5 2
1 6 1 -> 116
2 1 5 -> 152
2 2 4
2 3 3
2 4 2 -> 224
2 5 1 -> 125
3 4 1 -> 134
4 3 1 -> 143
*/

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  long long N;
  cin >> N;

  long long ans = (N - 1) * (N - 2) / 2;

  // a = b = c -> 중복 x
  if (N % 3 == 0) {
    cout << (ans + 2) / 3 << "\n";
  } else {
    cout << ans / 3 << "\n";
  }

  return 0;
}