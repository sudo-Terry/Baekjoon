#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000001
bool visited[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    visited[temp] = true;
  }

  int cnt = 0; // 윈도우 내에 존재하는 원소 수
  for(int i = 0; i < 5; i++){
    if(visited[i]) cnt++;
  }
  int ans = 5 - cnt;
  for(int right = 5; right < MAX; right++){
    int left = right - 4;

    if(visited[right]) cnt++;
    if(visited[left - 1]) cnt--;
  }

  // if(cnt < 5) cout << 5 - cnt;
  // else cout << '0';

  return 0;
}