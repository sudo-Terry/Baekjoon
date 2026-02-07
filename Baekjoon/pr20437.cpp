#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    string W;
    int K;
    cin >> W >> K;

    int ans3 = INT_MAX;
    int ans4 = -1;

    // 알파벳 a부터 z까지 각각 투 포인터
    for(int i = 0; i < 26; i++){
      char target = 'a' + i;
      int count = 0;
      int left = 0;

      // 해당 알파벳에 대해서만 투 포인터 수행
      for(int right = 0; right < W.size(); right++){
        if(W[right] == target) {
          count++;
        }

        // target 문자가 K개가 되었다면
        if(count == K){
          // left를 당겨서 정확히 구간을 맞춤
          // (target이 아닌 문자는 건너뛰고, target을 만나면 멈춤)
          while(W[left] != target){
            left++;
          }
          
          // 이 시점에서 W[left] == target, W[right] == target, 내부에 target K개
          int len = right - left + 1;
          ans3 = min(ans3, len);
          ans4 = max(ans4, len);

          // 다음 탐색을 위해 left를 한 칸 전진시키고 count 감소
          left++;
          count--;
        }
      }
    }

    if(ans3 == INT_MAX || ans4 == -1) cout << -1 << '\n';
    else cout << ans3 << ' ' << ans4 << '\n';
  }
  return 0;
}