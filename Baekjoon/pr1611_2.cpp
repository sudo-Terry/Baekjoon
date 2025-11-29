#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, M, Q;
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> counter;
  
  cin >> N >> M >> Q;
  adj.resize(N + 1);
  visited.resize(N + 1, false);
  counter.resize(N + 1, 0);
  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < Q; i++){
    int q, node;
    cin >> q >> node;

    if(q == 1){
      if(!visited[node]){
        visited[node] = true;
        for(size_t j = 0; j < adj[node].size(); j++){
          counter[adj[node][j]] += 1;
        }
      }
    }else{
      cout << counter[node] << '\n';
    }
  }

  return 0;
}