#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> L;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;

    if (L.empty() || num > L.back()) {
      L.push_back(num);
    }else {
      auto it = lower_bound(L.begin(), L.end(), num);
      *it = num;
    }
  }

  cout << L.size() << '\n';

  return 0;
}