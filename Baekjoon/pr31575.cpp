#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX 310

int N, M;
bool matrix[MAX][MAX] = {false, };

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
    // adj[v].push_back(u);
  }

  void sortList() {
    for (int i = 0; i < nodeCount; i++) {
      sort(adj[i].begin(), adj[i].end());
    }
  }

  void dfs(){
    fill(visited.begin(), visited.end(), false);
    dfs(0);
    cout << "No";
  }

  private:
  void dfs(int node) {
    visited[node] = true;
    
    if(node == (M - 1) * N + N - 1) {
      cout << "Yes";
      exit(0);
    }
    
    for (int next : adj[node]) {
      if (!visited[next]) {
        dfs(next);
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

  cin >> N >> M;
  Graph graph(N * M);
  
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      int c; 
      cin >> c;
      matrix[j][i] = (c == 1);
    }
  }

  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      // 우 방향
      if (matrix[j][i] && matrix[j][i+1]) {
        graph.addEdge(
          j * N + i, 
          j * N + (i + 1)
        );
      }

      // 아래 방향
      if (matrix[j][i] && matrix[j+1][i]) {
        graph.addEdge(
          j * N + i, 
          (j + 1) * N + i
        );
      }
    }
  }


  graph.sortList();
  graph.dfs();
}

