#include <iostream>
#include <algorithm>
#include <stdlib.h>
//#include <bits/stdc++.h>

using namespace std;

//알고리즘
//노드 번호를 레벨과 k를 이용하여 표현한다 1 / 2~k+1 / k+2~k^2+k+1 
//각 레벨에 해당하는 노드는 k^level개 만큼 있다 
//자식 노드의 번호는 노드번호가 n일 경우 (n-1)*k+2 ~ n*k+1 부모 노드의 번호는 [n+k-2/k]
//비교하는 두 노드중 큰 노드를 부모노드로 올리면서 서로를 비교하여 공통 부모에 도달할까지 반복하며 len에 1을 더한다
long long n, k ,q;//n: 노드의 수 k: k진 q: 노드쌍의 수

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> q;
	while (q--) {
		long long a, b;
		long long len = 0;
		cin >> a >> b;
		if (k == 1)
			len = abs(a - b);
		else {
			while (a != b) {
				if (a > b) {
					a = (a + k - 2) / k;
					len++;
				}
				else {
					b = (b + k - 2) / k;
					len++;
				}
			}
		}
		cout << len << '\n';
	}
	return 0;
}