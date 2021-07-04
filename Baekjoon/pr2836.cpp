#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int n, m; // n: ����� m :������
vector<pair<int, int>> pos;
int temp1, temp2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		if(temp1 > temp2)
			pos.push_back({ temp2, temp1 });
	}
	sort(pos.begin(), pos.end());

	ll left = 0;
	ll right = 0;
	ll sum = 0;

	for (int i = 0; i < pos.size(); i++) {
		if (right < pos[i].first) { //������ ����� ���ϰ� ���� ��������
			sum += right - left;
			left = pos[i].first;
			right = pos[i].second;
		}
		else { //������ �ȹ������ �������� ����
			if (right < pos[i].second) {
				right = pos[i].second;
			}
		}
	}
	sum += right - left;
	sum += sum;
	sum += m;
	cout << sum << '\n';
}