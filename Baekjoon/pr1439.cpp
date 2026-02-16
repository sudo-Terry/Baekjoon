#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string S;
  cin >> S;
  
  char before = S[0];
  int dx = 0;
  for(char c : S){
    if(c != before) dx++;
    
    before = c;
  }

  cout << (dx / 2) + (dx % 2);

  return 0;
}