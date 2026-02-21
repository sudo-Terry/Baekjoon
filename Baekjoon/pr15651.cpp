#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void dfs() {
  if (arr.size() == M) {
    for (int x : arr) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1; i <= N; i++) {
    arr.push_back(i);
    dfs();
    arr.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  dfs();
  return 0;
}