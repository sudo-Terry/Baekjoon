#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

int startNode, endNode;
int dist[MAX + 1]; //시간
bool visited[MAX + 1]; //방문 여부;

void solve() {
	queue<int> q;
	q.push(startNode);
	dist[startNode] = 0;
	visited[startNode] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		int next1 = curr + 1;
		int next2 = curr - 1;
		int next3 = curr * 2;
		if (next3 < MAX + 1) {
			if (!visited[next3]) {//초회 방문
				visited[next3] = true;
				dist[next3] = dist[curr];
				q.push(next3);
			}
		}
		if (next2 >= 0) {
			if (!visited[next2]) {//초회 방문
				visited[next2] = true;
				dist[next2] = dist[curr] + 1;
				q.push(next2);
			}
		}
		if (next1 < MAX + 1) {
			if (!visited[next1]) {//초회 방문
				visited[next1] = true;
				dist[next1] = dist[curr] + 1;
				q.push(next1);
			}
		}
	}
}

int main() {
	cin >> startNode >> endNode;
	solve();
	cout << dist[endNode] << '\n';
	return 0;
}