#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string S;
  cin >> S;
  set<string> str_set;

for(int i = 0; i < S.size(); i++){
  for(int len = 1; len <= S.size() - i; len++){
    string sub_S = S.substr(i, len);
    str_set.insert(sub_S);
  }
}

  cout << str_set.size();

  return 0;
}