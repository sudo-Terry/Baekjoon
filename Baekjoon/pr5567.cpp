#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int bfs(int startNode){
  int counter = 0;
  queue<int> q;
  int depth = 0;

  q.push(startNode);
  visited[startNode] = true;

  while(!q.empty()){
    if(depth == 2) break;
    
    int q_size = q.size();
    while(q_size--){
      int currentNode = q.front();
      q.pop();
      for(int adjNode : adj[currentNode]){
        if(!visited[adjNode]){
          q.push(adjNode);
          visited[adjNode] = true;
          counter++;
        }
      }
    }
    depth++;
  }

  return counter;
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  adj.resize(n+1);
  visited.resize(n+1);
  fill(visited.begin(), visited.end(), false);
  
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cout << bfs(1);

  return 0;
}