#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
맨뒤-2부터 가장 앞 알파벳 
나머지에서 맨뒤-1부터 가장 앞 알파벳
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  
  string word;
  string best_word = "A";
  cin >> word;
  
  for(int i = 1; i < word.size() - 1; i++){
    for(int j = i + 1; j < word.size(); j++){
      
      string s1 = word.substr(0, i);
      string s2 = word.substr(i, j - i);
      string s3 = word.substr(j);

      reverse(s1.begin(), s1.end());
      reverse(s2.begin(), s2.end());
      reverse(s3.begin(), s3.end());

      string current_word = s1 + s2 + s3;

      if(current_word < best_word || best_word == "A"){
        best_word = current_word;
      }
    }
  }
  cout << best_word;

  return 0;
}