#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string input;
  queue<char> q;
  cin >> input;
  int ans = 0;
  for(size_t i = 0; i < input.size(); i++){
    q.push(input[i]);
  }

  while(!q.empty()){
    ans++;

    string ans_str = to_string(ans);
    for(size_t i = 0; i < ans_str.size(); i++){
      if(q.front() == ans_str[i]) q.pop();
    }
  }

  cout << ans;

  return 0;
}