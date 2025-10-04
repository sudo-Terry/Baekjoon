#include <iostream>
#include <vector>
#include <algorithm>
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
        cout << "NO\n";
    }

    private:
    void dfs(int node) {
        visited[node] = true;
        
        if(node == M * 10 + N) {
            cout << "YES\n";
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

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int c; 
            cin >> c;
            matrix[i][j] = (c == 1);
        }
    }

    // 우 방향
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 1; j++) {
            if (matrix[i][j] && matrix[i][j + 1]) {
                graph.addEdge(
                    M * 10 + j, 
                    M * 10 + (j + 1)
                );
            }
        }
    }


    // 아래 방향
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (matrix[i][j] && matrix[i + 1][j]) {
                graph.addEdge(
                    M * 10 + j, 
                    (M + 1) * 10 + j
                );
            }
        }
    }

}

