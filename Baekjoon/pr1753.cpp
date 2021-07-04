#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000
#define INF 987654321
using namespace std;

int dist[MAX + 1]; //dist[n]: 시작 노드부터 n번째 노드까지의 최단거리를 저장한다.
vector<pair<int, int>> adj[MAX + 1]; //pair<int, int> 종점노드 번호, 간선의 가중치
int v, e, start;

void solve() {
	priority_queue <pair<int, int>> pq;
	dist[start] = 0; //초기값
	pq.push(make_pair(0, start));//시작노드 > 시작노드

	while (!pq.empty()) {
		int cost = -pq.top().first; //간선의 가중치
		int curr = pq.top().second; //종점노드 번호
		pq.pop();
        
		//인접한 노드들 중에서 가장 거리가 짧은 것을 고른다
		for (int i = 0; i < adj[curr].size(); i++) {
			int currnear = adj[curr][i].first; //인접노드 번호
			int costnear = adj[curr][i].second; //인접노드까지의 가중치
			if (dist[currnear] > cost + costnear) {
				dist[currnear] = cost + costnear;//최솟값일 경우에는 업데이트
				pq.push(make_pair(-dist[currnear], currnear));
			}
		}
	}
}

int main() {
	int tmp, first, second;
	cin >> v >> e >> start;
	for (int i = 1; i <= e; i++) {
		cin >> tmp >> first >> second;
		adj[tmp].push_back(make_pair(first, second));
	}
	for (int i = 1; i <= v; i++)
		dist[i] = INF;
	solve();
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) 
			cout << "INF" << endl;
		else 
			cout << dist[i] << endl;
	}
	return 0;
}
