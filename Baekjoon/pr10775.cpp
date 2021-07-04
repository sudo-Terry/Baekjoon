#include <iostream>
#include <vector>
using namespace std;

int g, p, gi;
int num = 0;
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
	par[a] = b;
}

int main() {
	cin >> g >> p;
	par.resize(g + 1);
	for (int i = 0; i <= g; i++) {
		par[i] = i;
	}for (int i = 0; i < p; i++) {
		cin >> gi;
		int root = find(gi);
		if (root) {
			num++;
			merge(root, root - 1);
		}
		else { //도킹 불가
			break;
		}
	}
	cout << num << '\n';
	return 0;
}