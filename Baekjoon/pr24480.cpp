#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100010

int N, M, R;
vector<int> adj[MAX];
int visited[MAX];
int order[MAX];
int cnt = 1;

void dfs(int node) {
  visited[node] = 1;
  order[node] = cnt++;

  for (int next : adj[node]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M >> R;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end(), greater<int>());
  }

  dfs(R);

  for (int i = 1; i <= N; i++) {
    cout << order[i] << '\n';
  }
}