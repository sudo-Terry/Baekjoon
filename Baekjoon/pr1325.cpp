#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int tc;
int N, M;
vector<vector<int>> adj;
vector<bool> visited;
int visitedNode = 0;
int visitedMax = 0;
vector<int> ans_node;

void dfs(int nodeNum){
  if(visited[nodeNum]) return;

  visited[nodeNum] = true;
  visitedNode++;
  for(int i = 0; i < adj[nodeNum].size(); i++){
    dfs(adj[nodeNum][i]);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;
  adj.resize(N+1);
  visited.resize(N+1);
  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    adj[v].push_back(u);
  }
  
  for(int i = 1; i <= N; i++){
    fill(visited.begin(), visited.end(), false);
    visitedNode = 0;

    dfs(i);

    if(visitedMax == visitedNode){
      ans_node.push_back(i);
    }else if(visitedMax < visitedNode){
      visitedMax = visitedNode;
      ans_node.clear();
      ans_node.push_back(i);
    }
  }

  sort(ans_node.begin(), ans_node.end());

  for(int node : ans_node) cout << node << ' ';

  return 0;
}