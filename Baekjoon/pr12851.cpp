#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

int startNode, endNode;
int visitNum[MAX + 1]; //방문 횟수
int dist[MAX + 1]; //시간
bool visited[MAX + 1]; //방문 여부;

void solve() {
	queue<int> q;
	q.push(startNode);
	dist[startNode] = 0;
	visited[startNode] = true;
	visitNum[startNode] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		int next1 = curr + 1;
		int next2 = curr - 1;
		int next3 = curr * 2;
		if (next1 < MAX + 1) {
			if (!visited[next1]) {//초회 방문
				visited[next1] = true;
				visitNum[next1] = visitNum[curr];
				dist[next1] = dist[curr] + 1;
				q.push(next1);
			}
			else if (dist[next1] == dist[curr] + 1) {//재방문(무한루프 방지를 위해 큐에 다시 넣지는 않는다)
				visitNum[next1] += visitNum[curr]; //수빈이의 위치를 -1하고 +1을 하면 dist 차이가 2 이상임을 이용(1 차이나면 다른방법으로 온것)
			}
		}if (next2 >= 0) {
			if (!visited[next2]) {//초회 방문
				visited[next2] = true;
				visitNum[next2] = visitNum[curr];
				dist[next2] = dist[curr] + 1;
				q.push(next2);
			}
			else if (dist[next2] == dist[curr] + 1) {//재방문(무한루프 방지를 위해 큐에 다시 넣지는 않는다)
				visitNum[next2] += visitNum[curr];
			}
		}if (next3 < MAX + 1) {
			if (!visited[next3]) {//초회 방문
				visited[next3] = true;
				visitNum[next3] = visitNum[curr];
				dist[next3] = dist[curr] + 1;
				q.push(next3);
			}
			else if (dist[next3] == dist[curr] + 1) {//재방문(무한루프 방지를 위해 큐에 다시 넣지는 않는다)
				visitNum[next3] += visitNum[curr];
			}
		}
	}
}

int main() {
	cin >> startNode >> endNode;
	solve();
	cout << dist[endNode] << '\n' << visitNum[endNode] << '\n';
	return 0;
}