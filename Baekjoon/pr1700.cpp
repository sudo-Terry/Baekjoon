#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> vec(K);
  for(int i = 0; i < K; i++){
    cin >> vec[i];
  }

  vector<int> multitap;  // 현재 꽂혀 있는 전기용품
  int ans = 0;

  for(int i = 0; i < K; i++){
    int current = vec[i];

    // 이미 꽂혀 있음
    if(find(multitap.begin(), multitap.end(), current) != multitap.end())
      continue;

    // 빈 자리 있음
    if(multitap.size() < N){
      multitap.push_back(current);
      continue;
    }

    // 하나 빼야 함
    int idx_to_remove = -1;
    int farthest = -1;

    for(int j = 0; j < N; j++){
      int plugged = multitap[j];
      int next_use = MAX;

      for(int k = i + 1; k < K; k++){
        if(vec[k] == plugged){
          next_use = k;
          break;
        }
      }

      // 앞으로 안 쓰이면 바로 제거
      if(next_use == MAX){
        idx_to_remove = j;
        break;
      }

      // 가장 나중에 쓰이는 거 칮기
      if(next_use > farthest){
        farthest = next_use;
        idx_to_remove = j;
      }
    }

    multitap.erase(multitap.begin() + idx_to_remove);
    multitap.push_back(current);
    ans++;
  }

  cout << ans << "\n";
}