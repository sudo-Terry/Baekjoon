#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int tc;
  string str;
  while(true){
    cin >> tc;
    if(tc == 0) break;

    vector<string> strs;
    for(int i = 0; i < tc; i++){
      string temp;
      cin >> temp;
      strs.push_back(temp);
    }
    
    sort(strs.begin(), strs.end(), 
      [](string &a, string &b){
        string A = a;
        string B = b;

        for(char &c : A) c = tolower(c);
        for(char &c : B) c = tolower(c);
        
        return A < B;
      }
    );

    cout << strs[0] << '\n';
  }

  return 0;
}