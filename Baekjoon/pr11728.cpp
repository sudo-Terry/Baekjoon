#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  queue<int> A, B;
  vector<int> ans;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    A.push(temp);
  }
  for(int i = 0; i < M; i++){
    int temp;
    cin >> temp;
    B.push(temp);
  }

  while(!A.empty() && !B.empty()){
    if(A.front() <= B.front()){
      ans.push_back(A.front());
      A.pop();
    } else {
      ans.push_back(B.front());
      B.pop();
    }
  }

  while(!A.empty()){
    ans.push_back(A.front());
    A.pop();
  }

  while(!B.empty()){
    ans.push_back(B.front());
    B.pop();
  }

  for(size_t i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

  return 0;
}