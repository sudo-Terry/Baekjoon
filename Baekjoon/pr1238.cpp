#include <iostream>
#include <vector>
#include <queue>
#define MAX 10010
#define INF 987654321
using namespace std;

int n, m, x, ans = 0;
vector<pair<int, int>> adj1[MAX + 1];
vector<pair<int, int>> adj2[MAX + 1];
int dist1[MAX + 1];
int dist2[MAX + 1];

void Dijkstra1(int start) {
	priority_queue<pair<int, int>> pq;
	dist1[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj1[curr].size(); i++)
		{
			int next = adj1[curr][i].first;
			int nextCost = adj1[curr][i].second;

			if (dist1[next] > cost + nextCost)
			{
				dist1[next] = cost + nextCost;
				pq.push(make_pair(-dist1[next], next));
			}
		}
	}
}

void Dijkstra2(int start) {
	priority_queue<pair<int, int>> pq;
	dist2[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj2[curr].size(); i++)
		{
			int next = adj2[curr][i].first;
			int nextCost = adj2[curr][i].second;

			if (dist2[next] > cost + nextCost)
			{
				dist2[next] = cost + nextCost;
				pq.push(make_pair(-dist2[next], next));
			}
		}
	}
}

int main() {
	int startNode, endNode, cost;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> startNode >> endNode >> cost;
		adj1[startNode].push_back(make_pair(endNode, cost));
		adj2[endNode].push_back(make_pair(startNode, cost));
	}
	for (int i = 1; i <= n; i++) {
		dist1[i] = INF;
		dist2[i] = INF;
	}
	Dijkstra1(x);
	Dijkstra2(x);
	for (int i = 1; i <= n; i++) {
		if (dist1[i] + dist2[i] > ans)
			ans = dist1[i] + dist2[i];
	}
	cout << ans << '\n';
	return 0;
}