#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100000
using namespace std;

//임의의 노드에서 가장 멀리떨어진 노드는 지름의 한쪽 끝이다
//그 점에서 다시 가장 멀리떨어진 노드를 구하여 거리를 구하면 트리의 지름을 구할 수 있다.

int n; //노드 수;
vector<pair<int, int>> adj[MAX + 1]; //pair<int, int> 종점노드 번호, 간선의 가중치
bool visited[MAX + 1];
int max1 = 0;
int max_node = 0;

void dfs(int node, int length) {
	if (visited[node])
		return;
	visited[node] = true;
	if (max1 < length) {
		max1 = length;
		max_node = node;
	}
	for (int i = 0; i < adj[node].size(); i++) {
		dfs(adj[node][i].first, length + adj[node][i].second);
	}
}

int main() {
	int tempNode, tempCost, tempCurr;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tempCurr;
		while (true) {
			cin >> tempNode;
			if (tempNode == -1)
				break;
			cin >> tempCost;
			adj[tempCurr].push_back(make_pair(tempNode, tempCost));
		}
	}
	dfs(1, 0);
	max1 = 0;
	memset(visited, 0, sizeof(visited));
	dfs(max_node, 0);
	cout << max1;
	return 0;
}