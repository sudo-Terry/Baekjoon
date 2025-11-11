#include <iostream>
using namespace std;

bool is_vowel(char c){
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u';
}

bool is_char_same(char c, char next_c){
  return c == next_c && c != 'e' && c!= 'o';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string input;
  while(true){
    cin >> input;
    if(input == "end") break;

    bool flag_1 = true;
    bool flag_2 = false;
    bool flag_3 = false;

    for(int i = 0; i < input.size(); i++){ 
      // 1번 조건
      if(is_vowel(input[i])) flag_1 = false; 
      
      // 2번 조건
      if(i < input.size() - 2){
        if(is_vowel(input[i]) == is_vowel(input[i + 1]) && is_vowel(input[i]) == is_vowel(input[i + 2]))
          flag_2 = true;
      }

      // 3번 조건
      if(i < input.size() - 1)
        if(is_char_same(input[i], input[i+1])) flag_3 = true;
    }

    cout << "<" + input + "> is ";
    if(flag_1 || flag_2 || flag_3) cout << "not ";
    cout << "acceptable." << '\n';
  }

  return 0;
}