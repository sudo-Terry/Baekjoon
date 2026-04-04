#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 3001

int sushi_count[MAX];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, d, k, c;
  cin >> N >> d >> k >> c;

  vector<int> sushi(N + k);
  for(int i = 0; i < N; i++) cin >> sushi[i];
  // 회전초밥이니 이어붙이기 -> 약간 원순열 느낌?
  for(int i = N; i < N + k; i++){
    sushi[i] = sushi[i - N];
  }

  int left = 0;
  int right = k - 1;
  // 쿠폰에 있는 초밥은 항상 먹을 수 있다
  sushi_count[c]++;
  int sushi_type_count = 1;
  for(int i = left; i <= right; i++){
    if(sushi_count[sushi[i]] == 0) sushi_type_count++;
    sushi_count[sushi[i]]++;
  }
  
  int max_sushi_type_count = sushi_type_count;
  while(right < N + k - 1){
    sushi_count[sushi[left]]--;
    if(sushi_count[sushi[left]] == 0) sushi_type_count--;
    left++;

    right++;
    if(sushi_count[sushi[right]] == 0) sushi_type_count++;
    sushi_count[sushi[right]]++;

    max_sushi_type_count = max(max_sushi_type_count, sushi_type_count);
    // cout << left << ' ' << right << ' ' << max_sushi_type_count << '\n';
  }

  cout << max_sushi_type_count;

  return 0;
}