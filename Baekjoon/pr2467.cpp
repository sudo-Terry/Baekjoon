#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<long long> liquids;
  for(int i = 0; i < N; i++){
    long long temp;
    cin >> temp;
    liquids.push_back(temp);
  }

  pair<int, int> ans_idx;
  long long ans_sum = LLONG_MAX;
  int left = 0;
  int right = N - 1;
  while(left < right){
    long long sum = liquids[left] + liquids[right];
    
    if(abs(sum) < abs(ans_sum)){
      ans_sum = sum;
      ans_idx = {left, right};
    }

    if(sum == 0){
      break;
    }else if(sum > 0){
      right--;
    }else{ // sum < 0
      left++;
    }
  }

  cout << liquids[ans_idx.first] << ' ' << liquids[ans_idx.second];

  return 0;
}