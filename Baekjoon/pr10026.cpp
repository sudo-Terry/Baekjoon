#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define MAX 110
using namespace std;

int N;
char matrix_rgb[MAX][MAX];
char matrix_rb[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0}; // middle up right down left
int rgb_size = 0;
int rb_size = 0;

class Graph{
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

  void dfs(int node) {
    visited[node] = true;
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

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> matrix_rgb[i][j];

      if(matrix_rgb[i][j] == 'G') matrix_rb[i][j] = 'R';
      else matrix_rb[i][j] = matrix_rgb[i][j];
    }
  }

  Graph g_rgb(N * N);
  Graph g_rb(N * N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){ 
      for(int d = 0; d < 4; d++){
        int ni = i + dy[d];
        int nj = j + dx[d];
        if(ni >= 0 && ni < N && nj >= 0 && nj < N){
          if(matrix_rgb[i][j] == matrix_rgb[ni][nj]) g_rgb.addEdge(i * N + j, ni * N + nj);
          if(matrix_rb[i][j] == matrix_rb[ni][nj]) g_rb.addEdge(i * N + j, ni * N + nj);
        }
      }
    }
  }

  g_rgb.sortList();
  g_rb.sortList();

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){ 
      if(!g_rgb.visited[i * N + j]){
        g_rgb.dfs(i * N + j);
        rgb_size++;
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){ 
      if(!g_rb.visited[i * N + j]){
        g_rb.dfs(i * N + j);
        rb_size++;
      }
    }
  }

  cout << rgb_size << ' ' << rb_size;

  return 0;
}