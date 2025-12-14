#include <iostream>
#include <cstring>
using namespace std;

int freq[26];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string word;
  cin >> word;
  for(char c : word){
    if(c >= 'A' && c <= 'Z') freq[c - 'A']++;
    else freq[c - 'a']++;
  }

  int freq_time = 0;
  int freq_idx = 0;
  bool flag = false;
  for(int i = 0; i < 26; i++){
    if(freq[i] > freq_time){
      freq_time = freq[i];
      freq_idx = i;
      flag = false;
    }else if(freq[i] == freq_time){
      flag = true;
    }
  }

  if(flag) cout << "?";
  else cout << (char)(freq_idx + 'A');

  return 0;
}