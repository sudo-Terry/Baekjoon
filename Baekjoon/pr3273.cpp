#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, target;
  vector<int> vec;
  cin >> n;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }
  cin >> target;

  sort(vec.begin(), vec.end());

  int left = 0;
  int right = n - 1;
  int ans = 0;
  while(left != right){
    if(target == vec[left] + vec[right]){
      ans++;
      left++;
    }else if(target > vec[left] + vec[right]){
      left++;
    }else if(target < vec[left] + vec[right]){
      right--;
    }
  }

  cout << ans;

  return 0;
}