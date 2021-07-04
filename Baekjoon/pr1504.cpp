#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 810
#define INF 987654321
using namespace std;

//�˰��� >> dijkstra�� ���� v1�� v2���� 1�� N������ �ִܰŸ��� ���ϰ� �̸� �����Ͽ� �ִܰŸ��� ���Ѵ�

int n, e;//���� ������ ��
int v1 = 0, v2 = 0;//�ݵ�� ������ �ϴ� ���
vector<pair<int, int>> adj[MAX];//��������Ʈ
bool visited[MAX];
int dist[MAX];
int ans;
int start_v1, start_v2, end_v1, end_v2;

void Dijkstra(int start){
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

void solve() {
	bool flag1 = true, flag2 = true;

	for (int i = 1; i <= n; i++) 
		dist[i] = INF;
	Dijkstra(1);

	int route1 = dist[v1];
	int route2 = dist[v2];
	if (route1 == INF)
		flag1 = false;
	if (route2 == INF) 
		flag2 = false;

	for (int i = 1; i <= n; i++) 
		dist[i] = INF;
	Dijkstra(v1);
	if (flag1 == true) 
		route1 = route1 + dist[v2];
	if (flag2 == true) 
		route2 = route2 + dist[v2];

	for (int i = 1; i <= n; i++) 
		dist[i] = INF;
	Dijkstra(v2);
	if (flag1 == true) 
		route1 = route1 + dist[n];

	for (int i = 1; i <= n; i++) 
		dist[i] = INF;
	Dijkstra(v1);
	if (flag2 == true) 
		route2 = route2 + dist[n];

	if (flag1 == false && flag2 == false) 
		ans = -1;
	else{
		ans = min(route1, route2);
	}

	if (ans == INF) 
		ans = -1;
}

int main() {
	int node1, node2, len;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> node1 >> node2 >> len;
		adj[node1].push_back(make_pair(node2, len));
		adj[node2].push_back(make_pair(node1, len));
	}
	cin >> v1 >> v2;
	solve();
	cout << ans;
	return 0;
}