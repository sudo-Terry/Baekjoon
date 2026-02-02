#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
bool visited[9];

void solve(int count){
  if(count == M){
    for(int x : arr) cout << x << ' ';
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; i++){
    if(visited[i]) continue;

    visited[i] = true;
    arr.push_back(i);

    solve(count + 1);

    arr.pop_back();
    visited[i] = false;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  solve(0);

  return 0;
}