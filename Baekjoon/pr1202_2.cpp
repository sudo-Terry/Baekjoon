#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
다음 최적해를 위한 선택인가 -> 흠... 가방 제일 작은걸로 제일 비싼놈 가져오면 되지 않을까
전체 문제가 부분 문제의 최적해긴 함 -> 고르고 나머지 가방으로 최대 가격을 만드는 것
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, K;
  vector<pair<int, int>> gem;
  multiset<int> bags;
  cin >> N >> K;
  
  for(int i = 0; i < N; i++){
    int M, V;
    cin >> M >> V;
    gem.push_back({M, V});
  }
  for(int i = 0; i < K; i++){
    int C;
    cin >> C;
    bags.insert(C);
  }

  // 가격순 정렬
  sort(gem.begin(), gem.end(), 
    [](pair<int, int> &gem1, pair<int, int> &gem2){
      return gem1.second > gem2.second;
    }
  );

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    // 남은 가방이 없으면 종료
    if (bags.empty()) break;

    // 현재 보석 무게보다 크거나 같은 가방 중 가장 작은 가방을 찾음
    auto it = bags.lower_bound(gem[i].first);

    // 찾았다면 담기
    if (it != bags.end()) {
        ans += gem[i].second;
        bags.erase(it);
    }
  }

    cout << ans;

  return 0;
}