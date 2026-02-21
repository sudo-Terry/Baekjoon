#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void dfs(int start) {
  if (arr.size() == M) {
    for (int x : arr) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = start; i <= N; i++) {
    arr.push_back(i);
    dfs(i);
    arr.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  dfs(1);
  return 0;
}