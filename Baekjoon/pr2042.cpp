#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

vector<ll> segTree;
ll n, m, k; //n: 리프 노드의 수 
ll a, b, c;
ll base = 2;

void init() {
	for (ll i = base - 1; i >= 1; i--) {
		segTree[i] = segTree[i * 2] + segTree[i * 2 + 1];
	}
}

ll solve(int b, int c, int index, int left, int right) {
	if (c < left || b > right) { //내가 저 구간에 속하지 않음 (7~8) : return 기본값
		return 0;
	}
	else if (b <= left && right <= c) { //내가 저 구간에 완전히 속함 (2~4) : return 나
		return segTree[index];
	}
	else { // 둘 다 아닐경우 : 자식들에게 시켜 left right 둘다 + merge 한값 return
		int mid = (left + right) / 2;
		return solve(b, c, 2 * index, left, mid) + solve(b, c, 2 * index + 1, mid +1, right);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int temp;
	cin >> n >> m >> k;
	while (base < n) {
		base *= 2;
	}
	segTree.resize(base * 2);
	for (ll i = 0; i < n; i++) {
		cin >> temp;
		segTree[base + i] = temp;
	}
	init();
	for (int i = 1; i <= m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {//b번째 수를 c로 바꾼다
			int tempNode = base + b - 1;
			segTree[tempNode] = c;
			while (1) { //update
				tempNode /= 2;
				segTree[tempNode] = segTree[tempNode * 2] + segTree[tempNode * 2 + 1];
				if (tempNode == 1) //루트 노드까지 업데이트를 끝냈으면 탈출한다
					break;
			}
			/*for (int cur : segTree) {
				cout << cur << ' ';
			}cout << '\n';*/
		}
		else {// 구간 [b, c]의 합을 구한다.
			cout << solve(b, c, 1, 1, base) << '\n';
		}
	}
	return 0;
}