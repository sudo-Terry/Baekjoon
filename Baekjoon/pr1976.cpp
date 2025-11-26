#include <iostream>
#include <vector>
using namespace std;
#define MAX 210

int N, M;
vector<vector<int>> adj;
vector<int> plan;
bool visited[MAX];

void dfs(int node_num){
  visited[node_num] = true;

  for(size_t i = 0; i < adj[node_num].size(); i++){
    if(!visited[adj[node_num][i]]){
      dfs(adj[node_num][i]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;
  adj.resize(N+1);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int temp;
      cin >> temp;
      if (temp == 1) adj[i+1].push_back(j+1);
    }
  }

  plan.resize(M);
  for(int i = 0; i < M; i++){
    cin >> plan[i];
  }

  dfs(plan[0]);

  bool flag = true;
  for(size_t i = 0; i < plan.size(); i++){
    if(!visited[plan[i]]) flag = false;
  }

  if(flag) cout << "YES";
  else cout << "NO";

  return 0;
}