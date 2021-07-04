#include <iostream>
#include <vector>
#define MAX 100

using namespace std;
long long memo[MAX+1] = { 0, };

//알고리즘 > P(n) + P(n+1) = P(n+3)  P(1~3) = 1

long long solve(int n) {
	if (memo[n])
		return memo[n];
	if (n <= 3)
		return memo[n] = 1;
	else 
		return memo[n] = solve(n - 3) + solve(n - 2);
}

int main(void) {
	int t = 0;
	int tempint;
	int answer = 0;
	vector<int> cases;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> tempint;
		cases.push_back(tempint);
	}

	for (int i = 0; i < t; i++) {
		cout << solve(cases[i]) << endl;
	}

	return 0;
}