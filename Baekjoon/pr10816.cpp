#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr_a;
vector<int> arr_m;
int n = 0, m = 0;
int low = 0;
int high = 0;
int sum = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr_a.push_back(temp);
	}
	sort(arr_a.begin(), arr_a.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		cout << upper_bound(arr_a.begin(), arr_a.end(), temp)
			- lower_bound(arr_a.begin(), arr_a.end(), temp)
			<< " ";
	}
	cout << '\n';

	return 0;
}