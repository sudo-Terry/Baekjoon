#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int K;
  cin >> K;
  vector<int> vec(K + 1);

  int temp;
  for(int i = 0; i < K; i++){
    cin >> temp;

    if(temp > 0) vec.push_back(temp);
    else vec.pop_back();
  }

  int sum = 0;
  for(size_t i = 0; i < vec.size(); i++) sum += vec[i];

  cout << sum;

  return 0;
}