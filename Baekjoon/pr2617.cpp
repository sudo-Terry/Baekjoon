#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 101

vector<int> heavier[MAX];
vector<int> lighter[MAX];
bool visited[MAX];

int dfs(int curr, const vector<int> adj[]) {
  int count = 0;
  for (int next : adj[curr]) {
    if (!visited[next]) {
      visited[next] = true;
      count += 1 + dfs(next, adj);
    }
  }
  return count;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    heavier[v].push_back(u);
    lighter[u].push_back(v);
  }

  int total_excluded = 0;
  int mid_limit = (N + 1) / 2;

  for (int i = 1; i <= N; i++) {
    memset(visited, false, sizeof(visited));
    int heavy_count = dfs(i, heavier);

    memset(visited, false, sizeof(visited));
    int light_count = dfs(i, lighter);

    if (heavy_count >= mid_limit || light_count >= mid_limit) {
      total_excluded++;
    }
  }

  cout << total_excluded << endl;

  return 0;
}