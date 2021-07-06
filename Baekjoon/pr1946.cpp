#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100100

int tc, n, ans = 0;
pair<int, int> score[MAX]; //score[i].first == document  score[i].second == interview
int interviewEnd;


void solve() {
	ans = 0;
	sort(score, score + n);
	ans++; // 서류전형 1등 채용
	interviewEnd = score[0].second;
	for (int i = 1; i < n; i++) {
		if (score[i].second < interviewEnd){
			ans++;
			interviewEnd = score[i].second;
		}
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> score[i].first >> score[i].second;
		}
		solve();
	}
	return 0;
}
