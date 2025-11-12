#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N, ans;
  char game_type;
  set<string> user_list;

  cin >> N >> game_type;
  while(N--){
    string temp;
    cin >> temp;
    user_list.insert(temp);
  }

  if(game_type == 'Y'){
    ans = user_list.size();
  }else if(game_type == 'F'){
    ans = user_list.size() / 2;
  }else if(game_type == 'O'){
    ans = user_list.size() / 3;
  }

  cout << ans;

  return 0;
}