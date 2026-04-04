#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#define MAX 810
#define INF 10000000
using namespace std;

vector<pair<int, int>> adj[MAX];
bool visited[MAX];
int dist[MAX];
int ans = 0;

// v1 v2 반드시 통과 
// 1 -> v1 -> v2 -> N
// 1 -> v2 -> v1 -> N
// 둘 중 최단거리

void dijkstra(int start){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

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
				dist[next] = cost + nextCost;
				pq.push({dist[next], next});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	int n, e;
	int v1, v2;
	cin >> n >> e;
	int node1, node2, len;
	for (int i = 0; i < e; i++) {
		cin >> node1 >> node2 >> len;
		adj[node1].push_back({node2, len});
		adj[node2].push_back({node1, len});
	}
	cin >> v1 >> v2;

	for(int i = 1; i < MAX; i++) dist[i] = INF;
	dijkstra(1);
	int st_to_v1 = dist[v1];
	int st_to_v2 = dist[v2];

	for(int i = 1; i < MAX; i++) dist[i] = INF;
	for(int i = 1; i < MAX; i++) visited[i] = false;
	dijkstra(v1);
	int v1_to_v2 = dist[v2];
	int v1_to_n = dist[n];
	
	for(int i = 1; i < MAX; i++) dist[i] = INF;
	for(int i = 1; i < MAX; i++) visited[i] = false;
	dijkstra(v2);
	int v2_to_v1 = dist[v1];
	int v2_to_n = dist[n];

	ans = min(
		st_to_v1 + v1_to_v2 + v2_to_n,
		st_to_v2 + v2_to_v1 + v1_to_n
	);
	
	if(ans >= INF) cout << "-1";
	else cout << ans;

	return 0;
}