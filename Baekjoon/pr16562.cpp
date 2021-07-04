#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> par; //first: 风飘何葛 second: 模备厚
int n, m, k, v, w;
int sum = 0;

int find(int n) {
	if (n == par[n].first)
		return n;
	else
		return par[n].first = find(par[n].first);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		par[b].first = a;
		if (par[b].second > par[a].second)
			par[b].second = par[a].second;
		else
			par[a].second = par[b].second;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	par.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		par[i] = make_pair(i, temp);
	}for (int i = 1; i <= m; i++) {
		cin >> v >> w;
		merge(v, w);
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
			sum += par[i].second;
		}
	}
	if (sum > k) {
		cout << "Oh no" << '\n';
	}
	else {
		cout << sum << '\n';
	}
	return 0;
}