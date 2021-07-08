#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1010
#define INF 987654321

int m, n, k;
int startNode, endNode, cost;
int origin, destination;
int dist[MAX];
int route[MAX];
vector<int> routeV;
vector<pair<int, int>> adj[MAX + 1];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 }; // middle up right down left

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()){
		int cost = -pq.top().first; //간선을 오름차순으로 방문하기 위해
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++){ //현재 노드들과 인접한 노드들에 대하여
			int next = adj[curr][i].first; //인접 노드 번호
			int nextCost = adj[curr][i].second; //인접 노드로의 가중치
			if (dist[next] > cost + nextCost){ //현재 dist값보다 최소비용이면 갱신한다
				route[next] = curr; // next에 해당하는 노드까지 최소비용으로 도달하기 위한 출발 노드인 curr노드 번호를 기록
				dist[next] = cost + nextCost;
				pq.push(make_pair(-dist[next], next)); 
			}
		}
	}
	int t = destination;
	while (t) {
		routeV.push_back(t);
		t = route[t];
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;    //   m: x     n: y
	for (int i = 0; i < m; i++) {
		cin >> startNode >> endNode >> cost;
		adj[startNode].push_back(make_pair(endNode, cost));
	}
	cin >> origin >> destination;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dijkstra(origin);
	cout << dist[destination] << '\n';
	cout << routeV.size() << endl;
	for (int i = routeV.size() - 1; i >= 0; i--) cout << routeV[i] << " ";
	cout << endl;
	return 0;
}
