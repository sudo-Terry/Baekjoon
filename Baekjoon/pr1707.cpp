#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 20010

vector<int> adj[MAX];
// 0: 방문X, 1 ~ 2: 그룹번호
int visited[MAX]; 
int V, E;

bool is_ans(int node, int color) {
  visited[node] = color;

  for (int i = 0; i < adj[node].size(); i++) {
    int next = adj[node][i];
    
    if (visited[next] == 0) { // 방문하지 않은 노드
      if (!is_ans(next, 3 - color)) return false; 
    } else if (visited[next] == visited[node]) { // 인접 노드가 같은 색
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> V >> E;
  for (int i = 1; i <= V; i++) {
    adj[i].clear();
    visited[i] = 0;
  }

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool result = true;
  for (int i = 1; i <= V; i++) {
    if (visited[i] == 0) {
      if (!is_ans(i, 1)) {
        result = false;
        break;
      }
    }
  }

  if (result) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int K;
  cin >> K;
  while (K--) {
    solve();
  }

  return 0;
}