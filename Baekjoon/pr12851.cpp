#include<iostream>
#include<queue>
#define MAX 100000
using namespace std;

int startNode, endNode;
int visitNum[MAX + 1]; //�湮 Ƚ��
int dist[MAX + 1]; //�ð�
bool visited[MAX + 1]; //�湮 ����;

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
			if (!visited[next1]) {//��ȸ �湮
				visited[next1] = true;
				visitNum[next1] = visitNum[curr];
				dist[next1] = dist[curr] + 1;
				q.push(next1);
			}
			else if (dist[next1] == dist[curr] + 1) {//��湮(���ѷ��� ������ ���� ť�� �ٽ� ������ �ʴ´�)
				visitNum[next1] += visitNum[curr]; //�������� ��ġ�� -1�ϰ� +1�� �ϸ� dist ���̰� 2 �̻����� �̿�(1 ���̳��� �ٸ�������� �°�)
			}
		}if (next2 >= 0) {
			if (!visited[next2]) {//��ȸ �湮
				visited[next2] = true;
				visitNum[next2] = visitNum[curr];
				dist[next2] = dist[curr] + 1;
				q.push(next2);
			}
			else if (dist[next2] == dist[curr] + 1) {//��湮(���ѷ��� ������ ���� ť�� �ٽ� ������ �ʴ´�)
				visitNum[next2] += visitNum[curr];
			}
		}if (next3 < MAX + 1) {
			if (!visited[next3]) {//��ȸ �湮
				visited[next3] = true;
				visitNum[next3] = visitNum[curr];
				dist[next3] = dist[curr] + 1;
				q.push(next3);
			}
			else if (dist[next3] == dist[curr] + 1) {//��湮(���ѷ��� ������ ���� ť�� �ٽ� ������ �ʴ´�)
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