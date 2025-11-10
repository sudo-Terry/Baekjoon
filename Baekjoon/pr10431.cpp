#include <iostream>
#include <vector>
using namespace std;

vector<int> child_height;
vector<int> child_ordered;

void solve(){
  int ans = 0;
  child_ordered.push_back(child_height[0]);

  for(int i = 1; i < 20; i++){
    bool inserted = false;

    for(int j = 0; j < child_ordered.size(); j++){
      if(child_ordered[j] > child_height[i]){
        ans += child_ordered.size() - j;
        child_ordered.insert(child_ordered.begin() + j, child_height[i]);
        inserted = true;
        break;
      }
    }

    if(!inserted) child_ordered.push_back(child_height[i]);
  }

  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc = 0;
  cin >> tc;

  while(tc--){
    child_height.clear();
    child_ordered.clear();

    int case_id;
    cin >> case_id;

    for(int i = 0; i < 20; i++){
      int temp;
      cin >> temp;
      child_height.push_back(temp);
    }

    cout << case_id << ' ';

    solve();
  }
}