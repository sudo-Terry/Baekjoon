#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> vec;
  
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }

  long long min_abs_sum = LLONG_MAX;
  vector<int> ans;
  sort(vec.begin(), vec.end());
  for(int i = 0; i < N; i++){
    int start = 0;
    int end = N - 1;

    while(start < end){
      if(start == i){
        start++;
        continue;
      }
      if(end == i){ 
        end--;
        continue;
      }

      long long sum = (long long)vec[i] + (long long)vec[start] + (long long) vec[end];

      if(min_abs_sum > abs(sum)){
        min_abs_sum = abs(sum);
        ans.clear();
        ans.push_back(vec[i]);
        ans.push_back(vec[start]);
        ans.push_back(vec[end]);
      }

      if(sum > 0){
        end--;
      }else{
        start++;
      }
    }
  }


  sort(ans.begin(), ans.end());
  for(int i : ans) cout << i << ' ';

  return 0;
}