#include <iostream>
#include <vector>
#include <queue>
#define MAX 20000
#define INF 987654321
using namespace std;

int dist[MAX + 1]; //dist[n]: ���� ������ n��° �������� �ִܰŸ��� �����Ѵ�.
vector<pair<int, int>> adj[MAX + 1]; //pair<int, int> ������� ��ȣ, ������ ����ġ
int v, e, start;

void solve() {
	priority_queue <pair<int, int>> pq;
	dist[start] = 0; //�ʱⰪ
	pq.push(make_pair(0, start));//���۳�� > ���۳��

	while (!pq.empty()) {
		int cost = -pq.top().first; //������ ����ġ
		int curr = pq.top().second; //������� ��ȣ
		pq.pop();
        
		//������ ���� �߿��� ���� �Ÿ��� ª�� ���� ����
		for (int i = 0; i < adj[curr].size(); i++) {
			int currnear = adj[curr][i].first; //������� ��ȣ
			int costnear = adj[curr][i].second; //������������ ����ġ
			if (dist[currnear] > cost + costnear) {
				dist[currnear] = cost + costnear;//�ּڰ��� ��쿡�� ������Ʈ
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
