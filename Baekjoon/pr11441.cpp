#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> vec_partial_sum; // vec[i]까지의 누적합

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  int temp;
  for(int i = 0; i < N; i++){
    cin >> temp;
    vec.push_back(temp);
  }
  vec_partial_sum.push_back(vec[0]);
  for(int i = 1; i < N; i++){
    vec_partial_sum.push_back(vec[i] + vec_partial_sum[i - 1]);
    // cout << vec_partial_sum[i] << '\n';
  }
  cin >> M;
  int start, end;
  for(int i = 0; i < M; i++){ // vps[j] - vps[i - 1]
    cin >> start >> end;
    cout << vec_partial_sum[end] - vec_partial_sum[start - 1] << '\n';
  }

  return 0;
}