#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string N;
  vector<int> vec_N;
  cin >> N;
  for(char& c : N){
    vec_N.push_back(c - '0');
  }
  sort(vec_N.begin(), vec_N.end(), greater<int>());
  
  for(size_t i = 0; i < vec_N.size(); i++){
    cout << vec_N[i];
  }

  return 0;
}