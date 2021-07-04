#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr_a;
vector<int> arr_m;
int n = 0, m = 0;
int low = 0;
int high = 0;

int solve(int ans, int low, int high) {
	if (low > high)
		return 0;
	int mid = (low + high) / 2;
	if (arr_a[mid] == ans)
		return 1;
	else if(ans < arr_a[mid])
		return solve(ans, low, mid - 1);
	else
		return solve(ans, mid + 1, high);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr_a.push_back(temp);
	}
	cin >> m;
	sort(arr_a.begin() , arr_a.end());
	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr_m.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		cout << solve(arr_m[i], 0, n-1) << '\n';
	}
	
	return 0;
}