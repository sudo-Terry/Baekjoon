#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int ans = 0;

  cin >> N;
  for(int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }
  sort(nums.begin(), nums.end());

  for(int i = 0; i < N; i++){
    int target = nums[i];
    int left = 0;
    int right = N - 1;

    while(left < right){
      if(left == i) { left++; continue; }
      if(right == i) { right--; continue; }

      int sum = nums[left] + nums[right];
      if(sum == target){
        ans++;
        break;
      } else if(sum < target){
        left++;
      } else {
        right--;
      }
    }
  }

  cout << ans;

  return 0;
}