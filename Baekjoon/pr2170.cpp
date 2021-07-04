#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<pair<int, int>> pos;
	int temp1, temp2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		pos.push_back({ temp1, temp2 });
	}
	sort(pos.begin(), pos.end());

	int left = -1000000000;
	int right = -1000000000;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (right < pos[i].first) { //구간을 벗어나면 더하고 새로 구간설정
			sum += right - left;
			left = pos[i].first;
			right = pos[i].second;
		}
		else { //구간을 안벗어났으면 우측값을 갱신
			if (right < pos[i].second) {
				right = pos[i].second;
			}
		}
	}
	sum += right - left;
	cout << sum << '\n';
}