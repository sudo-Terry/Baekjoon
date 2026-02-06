#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200010

int el_count[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];

  int left = 0;
  int ans = 0;
  for(int right = 0; right < N; right++){
    if(el_count[vec[right]] == K){ // 윈도우에 K개 있는 수가 right에 있을 경우
      // cout << left << ' ' << right << endl;
      while(vec[left] != vec[right]){ // 윈도우의 왼쪽 끝을 right에 있는 숫자가 나올때까지 이동
        el_count[vec[left]]--;
        left++;
      }
      el_count[vec[left]]--;
      left++;
      // cout << left << ' ' << right << endl;
    }
    el_count[vec[right]]++;
    ans = max(ans, right - left + 1);
  }

  cout << ans;

  return 0;
}