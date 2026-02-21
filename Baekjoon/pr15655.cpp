#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> nums;
vector<int> ans;

void dfs(int start) {
  if (ans.size() == M) {
    for (int x : ans)
      cout << x << ' ';
    cout << '\n';
    return;
  }

  for (int i = start; i < N; i++) {
    ans.push_back(nums[i]);
    dfs(i + 1);
    ans.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  
  nums.resize(N);
  for (int i = 0; i < N; i++)
    cin >> nums[i];

  sort(nums.begin(), nums.end());
  
  dfs(0);
}