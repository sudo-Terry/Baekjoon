#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

int time[MAX + 1] = { 0, };
int dp[MAX+1] = { 0, }; //dp[n] : ��ȣ�� n�� �ǹ��� ���� ���� ���������� �ɸ��� �ּ� �ð�
bool visited[MAX + 1];
vector<int> graph[1000]; //������ ��带 ��Ÿ����. <>�� ���س���� index []�� ����� ����� index
using namespace std;

//�˰��� >> 

int solve(int w) {
	int a = 0;
	visited[w] = true;
	while (graph[w][a] != 0) { //�ش� ����� ������ ���鿡 ���Ͽ�

	}
}

int main(void) {
	int t = 0;
	int n, k, w;//n: number of buildings  k: number of orders  w: target building number
	int tempint;
	int tempint2;

	cin >> t;
	while (t--) {
		memset(time, 0, sizeof(time));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 1000; i++) {
			memset(graph[i], 0, sizeof(graph[i]));
		}
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}
		cin >> n >> k;
		for (int i = 1; i <= k; i++) {
			cin >> tempint >> tempint2;
			graph[tempint].push_back(tempint2);
		}
		cin >> w;
		solve(w);
		cout << dp[w] << endl;
	}
	return 0;
}