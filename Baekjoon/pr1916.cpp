#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
#define INF 987654321
using namespace std;

int n, m; //n: 노드 수 m: 엣지 수
vector<pair<int, int>> adj[MAX + 1];
int dist[MAX + 1];
int startNode, endNode;

void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[curr].size(); i++)
		{
			int next = adj[curr][i].first;
			int nextCost = adj[curr][i].second;

			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int tempStart, tempEnd, tempCost;
	for (int i = 0; i < m; i++) {
		cin >> tempStart >> tempEnd >> tempCost;
		adj[tempStart].push_back(make_pair(tempEnd, tempCost));
	}
	cin >> startNode >> endNode;
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	Dijkstra(startNode);
	cout << dist[endNode];
	return 0;
}