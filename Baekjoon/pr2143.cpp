#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T, n, m;
  cin >> T >> n; 
  vector<long long> vec_a;
  for(int i = 0; i < n; i++){
    long long temp;
    cin >> temp;
    vec_a.push_back(temp);
  }
  cin >> m;
  vector<long long> vec_b;
  for(int i = 0; i < m; i++){
    long long temp;
    cin >> temp;
    vec_b.push_back(temp);
  }

  vector<long long> sum_a;
  for(int i = 0; i < n; i++){ 
    long long sum = 0;
    for(int j = i; j < n; j++){
      sum += vec_a[j];
      sum_a.push_back(sum);
    }
  }
  vector<long long> sum_b;
  for(int i = 0; i < m; i++){
    long long sum = 0;
    for(int j = i; j < m; j++){
      sum += vec_b[j];
      sum_b.push_back(sum);
    }
  }
  sort(sum_a.begin(), sum_a.end());
  sort(sum_b.begin(), sum_b.end());

  long long ans = 0;
  for(size_t i = 0; i < sum_a.size(); i++){
    long long target = T - sum_a[i];

    auto ub = upper_bound(sum_b.begin(), sum_b.end(), target);
    auto lb = lower_bound(sum_b.begin(), sum_b.end(), target);

    ans += (ub - lb);
  }

  cout << ans;

  return 0;
}