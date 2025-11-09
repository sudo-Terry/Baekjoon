#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, adj_count;
vector<vector<int>> adj;
vector<bool> visited;
int ans = 0;

void dfs(int node){
  visited[node] = true;
  ans++;

  for(int i = 0; i < adj[node].size(); i++){
    if(!visited[adj[node][i]]){
      dfs(adj[node][i]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> adj_count;
  adj.resize(n+1);
  visited.resize(n+1);
  for(int i = 0; i < adj_count; i++){
    int node_before, node_after;
    cin >> node_before >> node_after;
    adj[node_before].push_back(node_after);
    adj[node_after].push_back(node_before);
  }

  dfs(1);

  cout << ans - 1;

  return 0;
}