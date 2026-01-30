#include <iostream>
#include <stack>
using namespace std;

void solve(){
  string ps;
  cin >> ps;
  stack<char> stk;

  for(char c : ps){
    if(c == '('){
      stk.push(c);
    }else{
      if(!stk.empty()) stk.pop();
      else {
        cout << "NO" << '\n';
        return;
      }
    }
  }

  if(stk.empty()) cout << "YES" << '\n';
  else cout << "NO" << '\n';

  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--){
    solve();
  }

  return 0;
}