#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 100100
using namespace std;

int n, m, s;
vector<int> adj[MAX];
bool gomgom[MAX];
bool visited[MAX];
bool ans = false;
int src_node, dst_node, gomgom_num;

void dfs(int nodenum) {
  if (visited[nodenum] || gomgom[nodenum])
    return;
  visited[nodenum] = true;
  if (adj[nodenum].size() == 0) {
    // cout << nodenum << '\n';
    ans = true;
    return;
  }
  for(int i = 0; i < adj[nodenum].size(); i++){
    dfs(adj[nodenum][i]);
  }
}

void solve(){
  dfs(1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // memset(node, 0, sizeof(node));
  
  cin >> n >> m;
  
  for(int i = 0; i < m; i++){
    cin >> src_node >> dst_node;
    adj[src_node].push_back(dst_node);
  }
  
  cin >> s;
  
  for(int i = 0; i < s; i++){
    cin >> gomgom_num;
    gomgom[gomgom_num] = true;
  }
  
  solve();
  
  if (ans)
    cout << "yes";
  else
    cout << "Yes";

  return 0;
}