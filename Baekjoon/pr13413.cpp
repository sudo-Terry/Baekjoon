#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while(tc--){
    int s_len;
    string input, target;
    cin >> s_len >> input >> target;

    int w_to_b = 0;
    int b_to_w = 0;
    for(int i = 0; i < s_len; i++){      
      if(input[i] != target[i]){
        if(input[i] == 'W') w_to_b++;
        else b_to_w++;
      }
    }
    cout << max(w_to_b, b_to_w) << '\n';
  }

  return 0;
}