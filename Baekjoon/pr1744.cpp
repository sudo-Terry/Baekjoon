#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 그리디하게 2개씩 묶는게 기본
  // 0, 1은 묶지 말고, 음수가 홀수개면 하나는 남긴다
  int N;
  cin >> N;
  vector<int> mns_vec, pls_vec;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    if(temp > 0) pls_vec.push_back(temp);
    else mns_vec.push_back(temp);
  }

  sort(pls_vec.begin(), pls_vec.end(), greater<int>());
  sort(mns_vec.begin(), mns_vec.end());

  int ans = 0;
  for(size_t i = 0; i < pls_vec.size();){
    if(i == pls_vec.size() - 1){ // 홀수개면 마지막 원소는 걍 더하기
      ans += pls_vec[i];
      break;
    }

    if(pls_vec[i] > 1 && pls_vec[i + 1] > 1){
      ans += pls_vec[i] * pls_vec[i + 1];
    }else{
      ans += pls_vec[i];
      ans += pls_vec[i + 1];
    }
    // cout << pls_vec[i] << ' ' << pls_vec[i + 1] << ' ' << ans << endl;

    i += 2;
  }
    for(size_t i = 0; i < mns_vec.size();){
    if(i == mns_vec.size() - 1){ // 홀수개면 마지막 원소는 걍 더하기
      ans += mns_vec[i]; 
      break;
    }

    ans += mns_vec[i] * mns_vec[i + 1];

    i += 2;
  }

  cout << ans;

  return 0;
}