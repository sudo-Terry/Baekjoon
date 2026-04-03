#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> vec_ans;

void backtrack(int idx, int count){
  if(count == M){
    for(int i = 0; i < M; i++){
      cout << vec_ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  if(idx == N) return;

  int prev = -1;
  for(int i = idx; i < N; i++){ // 자식노드 목록
    if(vec[i] == prev) continue;

    vec_ans.push_back(vec[i]); // 노드 선택
    backtrack(i, count + 1); // 하나 골라서 다음 레벨
    vec_ans.pop_back(); // 노드 선택

    prev = vec[i];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  int temp;
  for(int i = 0; i < N; i++){
    cin >> temp;
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());

  backtrack(0, 0);

  return 0;
}