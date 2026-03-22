#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<int> graph[101];

int bfs(int start) {
  vector<int> dist(N + 1, -1);
  queue<int> q;
  
  q.push(start);
  dist[start] = 0;
  
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    
    for (int next : graph[curr]) {
      if (dist[next] == -1) {
        dist[next] = dist[curr] + 1;
        q.push(next);
      }
    }
  }
  
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += dist[i];
  }
  
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int ans = 0;
  int min = INT_MAX;

  for (int i = 1; i <= N; i++) {
    int res = bfs(i);
    
    if (res < min) {
      min = res;
      ans = i;
    }
  }
  
  cout << ans << '\n';

  return 0;
}