#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S, C, ans;
int max_len = 0;
vector<int> L;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> S >> C;
  int temp;
  for(int i = 0; i < S; i++){
    cin >> temp;
    L.push_back(temp);
    max_len = max(max_len, temp);
  }
  
  int left = 1;
  int right = max_len;
  int mid;
  while(left <= right){
    mid = (left + right) / 2;
    int chicken_count = 0;
    for(size_t i = 0; i < L.size(); i++){
      chicken_count += (L[i] / mid);
    }

    if(chicken_count < C){ // 파를 너무 크게 자른 경우
      right = mid - 1;
    }else{
      ans = max(ans, mid);
      left = mid + 1;
    }
  }

  long long total = 0;
  for(int i = 0; i < S; i++){
    total += L[i];
  }

  cout << total - (long long)ans * C;

  return 0;
}