#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string input;
  cin >> input;

  int ans = 0;
  for(size_t i = 0; i < input.size(); i++){
    char c = input[i];

    if(c == 'c'){
      if ( i + 1 < input.size() && input[i + 1] == '='
      || i + 1 < input.size() && input[i + 1] == '-'){
        i++;
      }
      ans++;
    }else if(c == 'd'){
      if ( i + 1 < input.size() && input[i + 1] == '-'){
        i++;
        ans++;
      }else if ( i + 2 < input.size() && input[i + 1] == 'z' && input[i + 2] == '='){
        ans++;
        i += 2;
      }else{
        ans++;
      }
    }else if(c == 'l'){
      if ( i + 1 < input.size() && input[i + 1] == 'j'){
        i++;
      }
      ans++;
    }else if(c == 'n'){
      if ( i + 1 < input.size() && input[i + 1] == 'j'){
        i++;
      }
      ans++;
    }else if(c == 's'){
      if ( i + 1 < input.size() && input[i + 1] == '='){
        i++;
      }
      ans++;
    }else if(c == 'z'){
      if ( i + 1 < input.size() && input[i + 1] == '='){
        i++;
      }
      ans++;
    }else{
      ans++;
    }
  }

  cout << ans;

  return 0;
}