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

//알고리즘
//dp[n][k] 의 정의: n번째 노드까지 입력 받았을 경우 최소 얼리 어답터의 수 k가 0이면 루트가 얼리어답터가 아닐때 k가 1이면 루트가 얼리어답터

void solve(int nodenum) {
	visited[nodenum] = true;
	dp[nodenum][0] = 0;//노드가 얼리어답터가 아니면 얼리어답터수는 변하지 않음
	dp[nodenum][1] = 1;//노드가 얼리어답터면 얼리어답터 수 증가
	for (int i = 0; i < adj[nodenum].size(); i++) {
		if (!visited[adj[nodenum][i]]) {
			solve(adj[nodenum][i]);
			dp[nodenum][0] += dp[adj[nodenum][i]][1]; //자신이 얼답터가 아니면 주변 노드가 전부 얼답터이어야 한다
			dp[nodenum][1] += min(dp[adj[nodenum][i]][0], dp[adj[nodenum][i]][1]); //자신이 얼답터면 주변이 얼답터일수도 아닐수도 있다.
		}
	}
}

int main() {
	int a, b;
	memset(visited, false, sizeof(visited));
	cin >> n; //노드의 수
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(1);
	cout << min(dp[1][0], dp[1][1]) << endl;
	return 0;
}