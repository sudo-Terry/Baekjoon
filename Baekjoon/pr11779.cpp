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
		int cost = -pq.top().first; //������ ������������ �湮�ϱ� ����
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[curr].size(); i++){ //���� ����� ������ ���鿡 ���Ͽ�
			int next = adj[curr][i].first; //���� ��� ��ȣ
			int nextCost = adj[curr][i].second; //���� ������ ����ġ
			if (dist[next] > cost + nextCost){ //���� dist������ �ּҺ���̸� �����Ѵ�
				route[next] = curr; // next�� �ش��ϴ� ������ �ּҺ������ �����ϱ� ���� ��� ����� curr��� ��ȣ�� ���
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
