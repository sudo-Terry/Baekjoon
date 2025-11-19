#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> x_pos;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int temp;
    cin >> temp;
    x_pos.push_back(temp);
  }

  int before = 0;
  // 첫 가로등 앞
  int max_dist = x_pos[0];

  // 마지막 가로등 뒤
  max_dist = max(max_dist, N - x_pos.back());

  for(size_t i = 1; i < x_pos.size(); i++){
    int dist = x_pos[i] - x_pos[i-1];
    
    // 가로등 사이는 양쪽에서 비추므로 2로 나눔 (홀수일 때 올림 처리 필요)
    // (dist + 1) / 2 는 정수 연산에서 올림 효과를 냄
    int height_needed = (dist + 1) / 2;
    
    max_dist = max(max_dist, height_needed);
  }

  cout << max_dist << '\n';

  return 0;
}