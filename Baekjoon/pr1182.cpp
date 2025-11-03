#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, S;
int num[20] = {0,};
int ans = 0;
int partial_sum = 0;

void dfs(int num_index){
  // 리프노드 도달
  if(num_index == N) return;
  
  if(partial_sum + num[num_index] == S) ans++;

  // 좌측분기
  dfs(num_index + 1);

  // 우측분기
  partial_sum += num[num_index];
  dfs(num_index + 1);

  // 위로
  partial_sum -= num[num_index];
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> S;
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  dfs(0);
  cout << ans;

  return 0;
}