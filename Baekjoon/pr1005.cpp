#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 1000

using namespace std;

int buildtime[MAX + 1];
int dp[MAX + 1]; //dp[n] : ��ȣ�� n�� �ǹ��� ���� ���� ���������� �ɸ��� �ּ� �ð�
int graph[MAX + 1][MAX + 1];
int t = 0;
int n, k, w;//n: number of buildings  k: number of orders  w: target building number

int solve(int w) {
    if (dp[w] != -1)
        return dp[w];
    int a = 0;
    for (int i = 1; i <=n; i++) { //�ش� ��忡 ������ ���鿡 ���Ͽ� ����Ѵ�
        if(graph[i][w])
            a = max(a, solve(i));
    }
    return dp[w] = a + buildtime[w];
}

int main(void) {
    int tempint;
    int tempint2;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> buildtime[i];
        }
        memset(dp, -1, sizeof(dp));
        memset(graph, 0, sizeof(graph));
        for (int i = 1; i <= k; i++) {
            cin >> tempint >> tempint2;
            graph[tempint][tempint2] = 1;
        }
        cin >> w;
        cout << solve(w) << '\n';
    }
    return 0;
}