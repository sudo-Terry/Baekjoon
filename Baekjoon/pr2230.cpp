#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 2100000000

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  vector <int> nums;

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  sort(nums.begin(), nums.end());
  
  // sub = right - left
  int left, right, sub = 0;
  int ans = INF;
  while(true){
    sub = nums[right] - nums[left];
    if(sub >= M && ans >= sub) ans = sub;

    if(sub <= M){ // 키우는 방향으로
      right++;
      if(right == N){
        cout << ans;
        return 0;
      }
    }else {
      left++;
    }
  }

  return 0;
}