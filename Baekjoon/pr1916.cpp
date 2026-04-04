#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
#define INF 987654321
using namespace std;

int n, m;
vector<pair<int, int>> adj[MAX + 1];
int dist[MAX + 1];
bool visited[MAX + 1];
int startNode, endNode;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({0, start}); // 최소 힙 -> 거리순 정렬되게 first를 dist로

	while (!pq.empty()){
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (visited[curr]) continue;
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

	cin >> n >> m;
	int tempStart, tempEnd, tempCost;
	for (int i = 0; i < m; i++) {
		cin >> tempStart >> tempEnd >> tempCost;
		adj[tempStart].push_back({tempEnd, tempCost});
	}

	cin >> startNode >> endNode;
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dijkstra(startNode);

	cout << dist[endNode];

	return 0;
}