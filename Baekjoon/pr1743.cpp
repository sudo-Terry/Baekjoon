#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define MAX 110
using namespace std;

int N, M, K;
bool matrix[MAX][MAX] = {false, };
int litterMax = 0;
int litterSize = 0;

class Graph {
  public:
  int nodeCount;
  vector<vector<int>> adj;
  vector<bool> visited;

  Graph(int nodeCount) : nodeCount(nodeCount) {
    adj.resize(nodeCount);
    visited.resize(nodeCount);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void sortList() {
    for (int i = 0; i < nodeCount; i++) {
      sort(adj[i].begin(), adj[i].end());
    }
  }

  void dfs(int col, int row){
    litterSize++;
    visited[col * M + row] = true;
    for (int next: adj[col * M + row]) {
      if (!visited[next]) {
        dfs(next / M, next % M);
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for (int i = 0; i < K; i++) {
    int r, c;
    cin >> r >> c;
    matrix[r - 1][c - 1] = true;
  }

  Graph g(N * M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(matrix[i][j]){
        if(i > 0 && matrix[i - 1][j]) g.addEdge((i - 1) * M + j, i * M + j); // 상
        if(i < N - 1 && matrix[i + 1][j]) g.addEdge((i + 1) * M + j, i * M + j); // 하
        if(j > 0 && matrix[i][j - 1]) g.addEdge(i * M + (j - 1), i * M + j); // 좌
        if(j < M - 1 && matrix[i][j + 1]) g.addEdge(i * M + (j + 1), i * M + j);  // 우
      }
    }
  }
  g.sortList();

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      litterSize = 0;
      g.dfs(i, j);
      if(litterSize > litterMax) litterMax = litterSize;
    }
  }

  cout << litterMax;

  return 0;
}