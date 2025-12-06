#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

#define EMPTY 0
#define BURGER 1
#define HUMAN 2


int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  vector<int> vec;
  int N, K;
  string input;
  cin >> N >> K;
  cin >> input;
  for(char& c : input){
    if(c == 'H') vec.push_back(BURGER);
    else if(c == 'P') vec.push_back(HUMAN);
  }

  int ans = 0;
  for(int i = 0; i < vec.size(); i++){
    if(vec[i] == HUMAN){
      int left = max(0, i - K);
      int right = min(N - 1, i + K);

      for(int j = left; j <= right; j++){
        if(vec[j] == BURGER){
          ans++;
          vec[i] = EMPTY;
          vec[j] = EMPTY;
          break;
        }
      }
    }
  }

  return 0;
}