#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n, k;
	int temp;
	int count = 0;
	vector<int> coins;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		coins.push_back(temp);
	}

	while (true) {
		for (int i = coins.size();;) {//Greedy_Alg ū������ ����
			if (k > 0) { //���� ���� �� �� ����
				if (coins.at(i - 1) > k) {//�ݾ��� �������� ������ ������ �����
					i--;
				}
				else {//�ݾ��� �������� ũ�� �ݾ׿��� ������ŭ�� ����.
					k -= coins.at(i - 1);
					count++;
				}
			}
			else { // k = 0
				cout << count;
				return 0;
			}
		}
		return -1;
	}
}