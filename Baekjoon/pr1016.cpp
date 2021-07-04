#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

long long minNum, maxNum;
long long arr[MAX + 1];

void solve() {
	long long temp = (long long)sqrt(minNum);
	for (int i = 0; i <= maxNum - minNum; i++) {
		arr[i] = minNum + i;
	}
	for (int i = 2; i <= MAX; i++) {
		for (long long j = i * i; j < maxNum; j += i * i) {
			if (minNum <= j) {
				arr[j - minNum] = 0;
			}
		}
	}
	int count = 0;
	for (int i = minNum; i < maxNum; i++) {
		if (arr[i - minNum] != 0)
			count++;
	}
	cout << count << '\n';
}

int main() {
	cin >> minNum >> maxNum;
	solve();
	return 0;
}