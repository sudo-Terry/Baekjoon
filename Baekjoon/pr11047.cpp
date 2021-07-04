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
		for (int i = coins.size();;) {//Greedy_Alg 큰수부터 뺀다
			if (k > 0) { //아직 수를 뺄 수 있음
				if (coins.at(i - 1) > k) {//금액이 단위보다 작으면 단위를 낮춘다
					i--;
				}
				else {//금액이 단위보다 크면 금액에서 단위만큼을 뺀다.
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