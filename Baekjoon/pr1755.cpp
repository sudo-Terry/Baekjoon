#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
0 zero 9
1 one 4
2 two 8 
3 three 7
4 four 2
5 five 1
6 six  6
7 seven 5
8 eight 0
9 nine 3
*/ 
char change_char(char c){
  if(c == '0') return '9';
  else if(c == '1') return '4';
  else if(c == '2') return '8';
  else if(c == '3') return '7';
  else if(c == '4') return '2';
  else if(c == '5') return '1';
  else if(c == '6') return '6';
  else if(c == '7') return '5';
  else if(c == '8') return '0';
  else return '3'; //if(c == '9')
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string start, end;
  vector<pair<string, int>> str_vec;
  cin >> start >> end;
  for(int i = stoi(start); i <= stoi(end); i++){
    string curr = to_string(i);
    for(size_t j = 0; j < curr.size(); j++){
      curr[j] = change_char(curr[j]);
    }
    str_vec.push_back({curr, i});
  }
  sort(str_vec.begin(), str_vec.end());

  for(size_t j = 0; j < str_vec.size(); j++){  
    cout << str_vec[j].second << ' ';
    if(j % 10 == 9) cout << '\n';
  }

  return 0;
}