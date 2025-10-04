#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 110

int N, M;
bool matrix[MAX][MAX] = {false, };
int height = 0;
int dx [] = {0, 1, 0, -1};
int dy [] = {-1, 0, 1, 0};

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

  void bfs(){
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
      int size = q.size();
      height++;
      for(int i = 0 ; i < size; i++){
        int node = q.front();
        q.pop();

        if(node == (N - 1) * M + M - 1){
          return;
        }

        for(int next: adj[node]){
          if(!visited[next]){
            visited[next] = true;
            q.push(next);
          }
        }
      }
    }
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      char c;
      cin >> c;
      matrix[i][j] = (c == '1');
    }
  }

  Graph g(N * M);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      for(int k = 0; k < 4; k++){
        int ni = i + dy[k];
        int nj = j + dx[k];
        if(ni >= 0 && ni < N && nj >= 0 && nj < M){
          if(matrix[i][j] && matrix[ni][nj]){
            g.addEdge(i * M + j, ni * M + nj);
          }
        }
      }
    }
  }
  g.sortList();

  g.bfs();

  cout << height;

  return 0;
}