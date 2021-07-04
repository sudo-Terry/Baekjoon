#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX 200100
using namespace std;
int tempPar[MAX];
int par[MAX];
int n, qc;

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
	int sol, node1, node2;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> qc;
	tempPar[1] = 1; //root
	for (int i = 2; i <= n; i++) {
		cin >> tempPar[i];
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	int count = n - 1 + qc;
	stack<pair<int, int>> querys;
	while (count--) {
		cin >> sol;
		if (sol) {//경로 존재 질의
			cin >> node1 >> node2;
			querys.push(make_pair(node1, node2));
		}
		else {//에지 제거
			cin >> node1;
			querys.push(make_pair(-1, node1));
		}
	}
	while (!querys.empty()) {
		if (querys.top().first == -1) {//에지 붙이기
			merge(querys.top().second, tempPar[querys.top().second]);
		}
		else {//경로 존재 질의
			if (find(querys.top().first) == find(querys.top().second))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		querys.pop();
	}
}