#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void solve() {
  string N;
  cin >> N;

  bool has_zero = false;
  long long sum = 0;

  for (char c : N) {
    if (c == '0') {
      has_zero = true;
    }
    sum += (c - '0'); 
  }

  if (!has_zero) {
    cout << -1 << "\n";
    return;
  }

  if (sum % 3 != 0) {
    cout << -1 << "\n";
    return;
  }

  sort(N.rbegin(), N.rend()); 

  cout << N << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  solve();
  
  return 0;
}