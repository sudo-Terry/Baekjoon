#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 1010
#define INF 987654321

int m, n, k;
int origin, destination;
int dist[MAX];
bool visited[MAX];
int prev_node[MAX];
vector<pair<int, int>> adj[MAX + 1];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()){
		int cost = pq.top().first; 
		int curr = pq.top().second;
		pq.pop();

		if(visited[curr]) continue;
		visited[curr] = true;

		for (int i = 0; i < adj[curr].size(); i++){ 
			int next = adj[curr][i].first;
			int nextCost = adj[curr][i].second;

			if (dist[next] > cost + nextCost){
				prev_node[next] = curr;

				dist[next] = cost + nextCost;
				pq.push(make_pair(dist[next], next)); 
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;    
	int u, v, cost;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({v, cost});
	}
	cin >> origin >> destination;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra(origin);

	cout << dist[destination] << '\n';
	
	stack<int> path;
	int cur = destination;
	while(true){
		path.push(cur);
		if(cur == origin) break;
		cur = prev_node[cur];
	}
	cout << path.size() << '\n';
	while (!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
	}

	return 0;
}
