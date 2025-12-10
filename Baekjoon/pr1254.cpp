#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool is_palindrome(string str){
  // 6 -> 0 1 2 3 4 5
  // 5 -> 0 1 2 3 4
  for(int i = 0; i <= str.size() / 2; i++){
    int start = i;
    int end = str.size() - 1 - i;
    if(str[start] == str[end]) continue;

    return false;
  }

  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string S;
  int palin_length;
  cin >> S;
  for(size_t i = 0; i < S.size(); i++){
    if(is_palindrome(S.substr(i, S.size()))){
      palin_length = S.size() - i;
      break;
    }
  }

  cout << S.size() + (S.size() - palin_length);

  return 0;
}