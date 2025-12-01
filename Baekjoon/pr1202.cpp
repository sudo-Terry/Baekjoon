#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
다음 최적해를 위한 선택인가 -> 흠... 가방마다 제일 비싼놈 가져오면 되지 않을까
전체 문제가 부분 문제의 최적해긴 함 -> 고르고 나머지 가방으로 최대 가격을 만드는 것

작은 가방이 담을 수 있는 보석은 큰 가방도 담을 수 있음 -> 이게 중요
작은 가방이 선택할 수 있는 최고가 보석을 먼저 선택해버리는 것이 전체 최적해를 보장
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, K;
  vector<pair<int, int>> gem;
  vector<int> bag_size;
  vector<bool> bag_used;
  cin >> N >> K;
  bag_used.resize(K, false);
  
  for(int i = 0; i < N; i++){
    int M, V;
    cin >> M >> V;
    gem.push_back({M, V});
  }
  for(int i = 0; i < K; i++){
    int C;
    cin >> C;
    bag_size.push_back(C);
  }
  sort(bag_size.begin(), bag_size.end());

  // 무게순 정렬
  sort(gem.begin(), gem.end(), 
    [](pair<int, int> &gem1, pair<int, int> &gem2){
      return gem1.first < gem2.first;
    }
  );

  priority_queue<int> pq;
  long long ans = 0;
  int gem_idx = 0;

  // 가방마다
  for(int i = 0; i < K; i++){
    // 가방에 넣을 수 있는 보석 다 담기
    // 전에 힙에 못넣은 보석만 확인
    while(gem_idx < N && gem[gem_idx].first <= bag_size[i]){
      pq.push(gem[gem_idx].second);
      gem_idx++;
    }

    // 제일 비싼 가격 하나 뽑기
    if(!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans;

  return 0;
}