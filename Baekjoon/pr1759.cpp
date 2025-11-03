#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int L, C;
char alph[30];
string partial_str = "";
int aeiou_cnt = 0;
int aeiou_else = 0;

void dfs(int index){
  // 리프노드 도달
  if(index > C || partial_str.length() > L) return;

  if ( aeiou_cnt >= 1 && aeiou_else >= 2 && partial_str.length() == L) {
    cout << partial_str << '\n';
  }

  // 좌측분기
  dfs(index + 1);

  // 우측분기
  partial_str += alph[index];
  if(alph[index] == 'a' ||
    alph[index] == 'e' ||
    alph[index] == 'i' ||
    alph[index] == 'o' ||
    alph[index] == 'u'
  ){
    aeiou_cnt++;
  }else{
    aeiou_else++;
  }
  dfs(index + 1);

  // 위로
  if(partial_str.find(alph[index]) != string::npos){
    if(alph[index] == 'a' ||
      alph[index] == 'e' ||
      alph[index] == 'i' ||
      alph[index] == 'o' ||
      alph[index] == 'u'
    ){
      aeiou_cnt--;
    }else{
      aeiou_else--;
    }
    partial_str.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> L >> C;
  for(int i = 0; i < C; i++){
    cin >> alph[i];
  }

  sort(alph, alph + C); 

  dfs(0);

  return 0;
}