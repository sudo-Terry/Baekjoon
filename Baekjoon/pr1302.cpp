#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  unordered_map<string, int> m;
  string s;

  for(int i = 0; i < N; i++){
    cin >> s;
    m[s]++;
  }

  string ans = "";
  int max_count = 0;

  for(auto &p : m){
    string title = p.first;
    int count = p.second;

    if(count > max_count){
      max_count = count;
      ans = title;
    }else if(count == max_count && title < ans){
      ans = title;
    }
  }

  cout << ans;
}