#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

vector<vector<int>> segTree;
ll n, m, base = 1;
int x, y, c;
int x_1, y_1, x_2, y_2;

void update(int ux, int uy, int d) {
	int i = uy + base - 1;
	int j = ux + base - 1;
	segTree[i][j] = d;
	while (j > 1) {
		j /= 2;
		segTree[i][j] = segTree[i][j * 2] + segTree[i][j * 2 + 1];
	}
	while (i > 1) {
		j = ux + base - 1;
		i /= 2;
		segTree[i][j] = segTree[i * 2][j] + segTree[i * 2 + 1][j];
		while (j > 1) {
			j /= 2;
			segTree[i][j] = segTree[i][j * 2] + segTree[i][j * 2 + 1];
		}
	}
	return;
}

int sol_x(int y, int nodeL, int nodeR, int nodeNum, int left, int right) {
	if (nodeL <= left && right <= nodeR)
		return segTree[y][nodeNum];
	else if (nodeR < left || right < nodeL)
		return 0;
	int mid = (left + right) / 2;
	return sol_x(y, nodeL, nodeR, nodeNum * 2, left, mid) + sol_x(y, nodeL, nodeR, nodeNum * 2 + 1, mid + 1, right);
}

int sol_y(int nodeL, int nodeR, int nodeNum, int left, int right, int x1, int x2){
	if (nodeL <= left && right <= nodeR) 
		return sol_x(nodeNum, x1, x2, 1, 1, base);
	else if (nodeR < left || right < nodeL) 
		return 0;
	int mid = (left + right) / 2;
	return sol_y(nodeL, nodeR, nodeNum * 2, left, mid, x1, x2) + sol_y(nodeL, nodeR, nodeNum * 2 + 1, mid + 1, right, x1, x2);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	while (base < n) 
		base <<= 1;
	segTree.resize(base * 2);
	for (int i = 0; i < base * 2; i++) {
		segTree[i].resize(base * 2);
	}
	for (int i = 1; i <= n; i++) { //leafNode 초기화단계
		for (int j = 1; j <= n; j++) {
			int t;
			cin >> t;
			update(i, j, t);
		}
	}
	for (int i = 0; i < m; i++) {
		int w;
		cin >> w;
		if (w) {
			cin >> x_1 >> y_1 >> x_2 >> y_2;
			if(x_1 > x_2){
				int tempX;
				tempX = x_1;
				x_1 = x_2;
				x_2 = tempX;
			}if (y_1 > y_2) {
				int tempY;
				tempY = y_1;
				y_1 = y_2;
				y_2 = tempY;
			}
			cout << sol_y(y_1, y_2, 1, 1, base, x_1, x_2) << '\n';
		}
		else {
			cin >> x >> y >> c;
			update(x, y, c);
		}
	}
	return 0;
}