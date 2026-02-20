#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define WIN_COUNT 6

int k = -1;
vector<int> vec;
vector<int> ans;

void backtrack(int idx){
  if(ans.size() == WIN_COUNT){
    for(size_t i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  if(idx == k) return;

  ans.push_back(vec[idx]);
  backtrack(idx + 1);

  ans.pop_back();
  backtrack(idx + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while(true){
    vec.clear();
    cin >> k;
    if(k == 0) break;

    for(int i = 0 ; i < k; i++){
      int temp;
      cin >> temp;
      vec.push_back(temp);
    }

    backtrack(0);

    cout << '\n';
  }

  return 0;
}