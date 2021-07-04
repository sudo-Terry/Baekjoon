#include <iostream>
#include <algorithm>
#define MAX 110
#define INF 987654321
using namespace std;

int ans, cnt;
int n, m, r, a, b, l;
int node[MAX];
int dist[MAX][MAX];

int main() {
	cin >> n >> m >> r;
	int tempStart, tempEnd, tempCost;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i != j)
				dist[i][j] = INF;
	}
	for (int i = 1; i <= n; i++) cin >> node[i];

	// 길과 길 사이의 거리 저장
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}

	for (int i = 1; i <= n; i++)
	{
		cnt = node[i];
		for (int j = 0; j <= n; j++)
		{
			if (i != j && dist[i][j] <= m) cnt += node[j];
		}
		ans = max(ans, cnt);
	}

	cout << ans;

}