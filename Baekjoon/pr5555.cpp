#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string target;
  int ring_count;
  vector<string> rings;

  cin >> target;
  cin >> ring_count;
  for(int i = 0; i < ring_count; i++){
    string temp;
    cin >> temp;
    rings.push_back(temp);
  }

  int ans = 0;
  for(int i = 0; i < rings.size(); i++){
    string ring = rings[i];
    ring += ring.substr(0, target.size()- 1);

    for(int j = 0; j <= ring.size() - target.size(); j++){
      cout << ring[j] << endl;
      bool flag = true;
      
      for(int k = 0; k < target.size(); k++){
        if(ring[j + k] != target[k]){
          flag = false;
          break;
        }
      }

      if(flag) {
        ans++;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}