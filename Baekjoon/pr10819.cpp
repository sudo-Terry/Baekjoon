#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> A;
vector<bool> visited;
vector<int> current;

int max_value = 0;

void dfs(int depth) {
  if (depth == N) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
      sum += abs(current[i] - current[i + 1]);
    }
    max_value = max(max_value, sum);
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      current.push_back(A[i]);

      dfs(depth + 1);

      current.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  A.resize(N);
  visited.resize(N, false);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  dfs(0);

  cout << max_value << "\n";
}