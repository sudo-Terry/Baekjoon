#include <iostream>
using namespace std;
#define MAX 110

int n;
int adj[MAX][MAX];

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (adj[j][i] && adj[i][k]) adj[j][k] = 1;
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	solve();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}
