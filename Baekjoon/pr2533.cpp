#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1000000

using namespace std;
int dp[MAX + 1][2];
bool visited[MAX + 1];
vector<int> adj[MAX + 1];
int n;

//�˰���
//dp[n][k] �� ����: n��° ������ �Է� �޾��� ��� �ּ� �� ������� �� k�� 0�̸� ��Ʈ�� �󸮾���Ͱ� �ƴҶ� k�� 1�̸� ��Ʈ�� �󸮾����

void solve(int nodenum) {
	visited[nodenum] = true;
	dp[nodenum][0] = 0;//��尡 �󸮾���Ͱ� �ƴϸ� �󸮾���ͼ��� ������ ����
	dp[nodenum][1] = 1;//��尡 �󸮾���͸� �󸮾���� �� ����
	for (int i = 0; i < adj[nodenum].size(); i++) {
		if (!visited[adj[nodenum][i]]) {
			solve(adj[nodenum][i]);
			dp[nodenum][0] += dp[adj[nodenum][i]][1]; //�ڽ��� ����Ͱ� �ƴϸ� �ֺ� ��尡 ���� ������̾�� �Ѵ�
			dp[nodenum][1] += min(dp[adj[nodenum][i]][0], dp[adj[nodenum][i]][1]); //�ڽ��� ����͸� �ֺ��� ������ϼ��� �ƴҼ��� �ִ�.
		}
	}
}

int main() {
	int a, b;
	memset(visited, false, sizeof(visited));
	cin >> n; //����� ��
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(1);
	cout << min(dp[1][0], dp[1][1]) << endl;
	return 0;
}