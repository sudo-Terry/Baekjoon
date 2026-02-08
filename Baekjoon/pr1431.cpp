#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<string> serials;
  while(N--){
    string serial;
    cin >> serial;
    serials.push_back(serial);
  }

  // 람다 -> a가 b보다 앞에 와야 하면 true
  sort(serials.begin(), serials.end(), [](const string &a, const string &b){
    //A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    if (a.length() != b.length())
      return a.length() < b.length();

    // 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 더한다)
    int a_sum = 0, b_sum = 0;
    for(size_t i = 0; i < a.size(); i++){
      if(a[i] >= '0' && a[i] <= '9') a_sum += a[i] - '0';
    }
    for(size_t i = 0; i < b.size(); i++){
      if(b[i] >= '0' && b[i] <= '9') b_sum += b[i] - '0';
    }

    if (a_sum != b_sum)
      return a_sum < b_sum;

    //만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.
    return a < b;
  });

  for(int i = 0; i < serials.size(); i++){
    cout << serials[i] << '\n';
  }

  return 0;
}