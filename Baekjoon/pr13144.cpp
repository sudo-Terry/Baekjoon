#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100010

bool visited[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) cin >> vec[i];

  sort(vec.begin(), vec.end());

  long long ans = 0;
  int left = 0;
  for (int right = 0; right < N; right++) {
    // 이미 숫자가 존재한다면, left를 옮겨서 중복을 제거
    while (visited[vec[right]]) {
      visited[vec[left]] = false;
      left++;
    }

    // 현재 숫자 방문 처리
    visited[vec[right]] = true;

    ans += (right - left + 1);
  }

  cout << ans;

  return 0;
}