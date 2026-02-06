#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000010

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> vec(N, 0);
  for(int i = 0; i < N; i++) {
    int start, end;
    cin >> start >> end;
    vec[start]++; 
    vec[end]--;
  }
  for(int i = 1; i < MAX; i++) {
    vec[i] += vec[i-1];
  }

  // 합이 K, 조건을 만족하는 A, B가 여러 개 존재할 때는 A가 가장 작은 경우를 출력
  int sum = 0;
  int left = 0, right = 0;
  while(right < MAX){
    if(sum == K){ 
      cout << left << ' ' << right;
      return 0;
    }else if(sum > K){ // 윈도우 내의 합이 초과하였으니, 왼쪽 슬라이드를 이동
      sum -= vec[left];
      left++;
    }else{ // 합이 작으니, 오른쪽 슬라이드를 확대
      sum += vec[right];
      right++;
    }
  }

  cout << "0 0";
  return 0;
}