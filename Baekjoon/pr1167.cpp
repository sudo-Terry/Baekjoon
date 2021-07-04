#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100000
using namespace std;

//������ ��忡�� ���� �ָ������� ���� ������ ���� ���̴�
//�� ������ �ٽ� ���� �ָ������� ��带 ���Ͽ� �Ÿ��� ���ϸ� Ʈ���� ������ ���� �� �ִ�.

int n; //��� ��;
vector<pair<int, int>> adj[MAX + 1]; //pair<int, int> ������� ��ȣ, ������ ����ġ
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