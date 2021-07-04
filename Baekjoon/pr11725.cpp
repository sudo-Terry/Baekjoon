#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100000
using namespace std;

vector <int> tempadj[MAX + 1];
int parent[MAX + 1]; //parent[n]은 n번 노드의 부모노드 번호를 저장한다
bool visited[MAX + 1];
queue<int> q;

void solve() {
	//부모 노드의 자식들을 찾아 부모를 루트로 하고 visited 상태변경
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