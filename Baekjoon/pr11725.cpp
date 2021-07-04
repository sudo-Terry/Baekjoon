#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100000
using namespace std;

vector <int> tempadj[MAX + 1];
int parent[MAX + 1]; //parent[n]�� n�� ����� �θ��� ��ȣ�� �����Ѵ�
bool visited[MAX + 1];
queue<int> q;

void solve() {
	//�θ� ����� �ڽĵ��� ã�� �θ� ��Ʈ�� �ϰ� visited ���º���
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < tempadj[curr].size(); i++) {
			int next = tempadj[curr][i];
			if (!visited[next]) {
				visited[curr] = true;
				parent[next] = curr;
				q.push(next);
			}
		}
	}
}

int main() {
	int n;
	int temp1, temp2;
	memset(visited, false, sizeof(visited));
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> temp1 >> temp2;
		tempadj[temp1].push_back(temp2);
		tempadj[temp2].push_back(temp1);
	}
	solve();
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}