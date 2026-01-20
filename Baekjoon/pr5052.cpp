#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;
  while(tc--){
    vector<string> vec;
    bool flag = false;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
      string temp;
      cin >> temp;
      vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    for(int i = 0; i < n - 1; i++){
      if (vec[i + 1].substr(0, vec[i].size()) == vec[i]) {
        flag = true;
        break;
      } 
    }

    if(flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';
  }

  return 0;
}