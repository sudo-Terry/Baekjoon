#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  adj.resize(101);
  visited.resize(101, false);
  for(int i = 1; i < 100; i++){
    for(int j = 6; j > 0; j--)
      if(i + j <= 100) adj[i].push_back(i+j);
  }

  for(int i = 0; i < N + M; i ++){
    int u, v;
    cin >> u >> v;
    for(int j = 0 ; j < 100; j++){
      for(int l = 0; l < adj[j].size(); l++){
        if(adj[j][l] == u) adj[j][l] = v; 
      }
    }
  }

  int ans = 0;
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while(!q.empty()){
    int q_size = q.size();
    while(q_size--){
      int current = q.front();
      q.pop();
      visited[current] = true;

      if(current == 100) {
        cout << ans;
        return 0;
      }

      for(int i = 0; i < adj[current].size(); i++){
        if(!visited[adj[current][i]]){
          q.push(adj[current][i]);
          
        }
      }
    }
    ans++;
  }

  return -1;
}