#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> vec_ans;

void backtrack(int idx){
  if(vec_ans.size() == M){
    for(int a : vec_ans) cout << a << ' ';
    cout << '\n';
    return;
  }

  if(idx == N) return;

  int prev = -1;
  for(int i = 0; i < N; i++){
    if(vec[i] == prev) continue;

    vec_ans.push_back(vec[i]);
    backtrack(i);
    vec_ans.pop_back();

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

  backtrack(0);

  return 0;
}