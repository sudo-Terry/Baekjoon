#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;

void bfs(int start){
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while(!q.empty()){
    int q_size = q.size();
    vector<int> ans;
    for(int i = 0; i < q_size; i++){
      int curr = q.front();
      q.pop();

      // ans.push_back(curr);
      cout << curr << ' ';

      for(int i = 0; i < adj[curr].size(); i++){
        if(!visited[adj[curr][i]]) {
          q.push(adj[curr][i]);
          visited[adj[curr][i]] = true;
        }
      }
    }

    // sort(ans.begin(), ans.end());
    // for(size_t i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  }

  cout << '\n';
}

void dfs(int start){
  visited[start] = true;

  cout << start << ' ';

  for(int i = 0; i < adj[start].size(); i++){
    if(!visited[adj[start][i]]) dfs(adj[start][i]);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M >> V;
  adj.resize(N + 1);
  visited.resize(N + 1);

  for(int i = 0 ; i < M; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());
  dfs(V);
  cout << '\n';

  for(int i = 1; i <= N; i++){
    visited[i] = false;
  }

  bfs(V);

  return 0;
}