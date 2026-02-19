#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> nums;

void dfs(long long num, int last) {
  nums.push_back(num);

  for (int i = 0; i < last; i++) {
    dfs(num * 10 + i, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i <= 9; i++) {
    dfs(i, i);
  }

  sort(nums.begin(), nums.end());

  if (N >= nums.size())
    cout << -1;
  else
    cout << nums[N];

  return 0;
}