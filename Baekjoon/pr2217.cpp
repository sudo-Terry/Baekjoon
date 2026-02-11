#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 물체의 최대 중량
// 로프 하나만 쓰면 가장 단단한 로프
// 로프 여러개 쓰면 가장 튼튼한 로프를 위에서부터 K개 선택한다
// 그 로프에는 각각 W/K 만큼의 힘이 걸린다

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> ropes;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    ropes.push_back(temp);
  }

  sort(ropes.begin(), ropes.end(), greater<int>());
  int ans = 0;
  for(int i = 0; i < N; i++){
    int k = i + 1;
    
  }


  return 0;
}