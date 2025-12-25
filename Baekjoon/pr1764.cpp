#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, M;
  unordered_set<string> not_heard;
  vector<string> ans;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    string name;
    cin >> name;
    not_heard.insert(name);
  }

  for(int i = 0; i < N; i++) {
    string name;
    cin >> name;
    if(not_heard.count(name)){
      ans.push_back(name);
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << '\n';
  }

  return 0;
}