#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 10

int N;
bool visited[MAX];
vector<int> ans;

void dfs(int idx){
  if(idx == N){
    for(size_t i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      visited[i] = true;
      ans.push_back(i);

      dfs(idx + 1);
      
      ans.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  
  cin >> N;

  dfs(0);

  return 0;
}