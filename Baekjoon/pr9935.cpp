#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string input, target;
  vector<char> final_str;
  cin >> input >> target;

  for(int i = 0; i < input.size(); i++){
    final_str.push_back(input[i]);

    if(final_str.size() >= target.size()){
      bool flag = false;

      for(int j = 0; j < target.size(); j++){
        if (final_str[final_str.size() - 1 - j] != target[target.size() - 1 - j]){
          flag = true;
          break;
        }
      }

      if(!flag){
        for(int j = 0; j < target.size(); j++){
          final_str.pop_back();
        }
      }
    }
  }

  if (final_str.size() == 0) cout << "FRULA";
  else{
    for(int i = 0; i < final_str.size(); i++){
      cout << final_str[i];
    }
  }
  

  return 0;
}