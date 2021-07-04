#include<iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> par;

int find(int n) {
	if (n == par[n])
		return n;
	else
		return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[b] = a;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	par.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	int temp, a, b;
	for (int i = 1; i <= m; i++) {
		cin >> temp >> a >> b;
		if (temp) { //find
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else { //merge
			merge(a, b);
		}
	}
}