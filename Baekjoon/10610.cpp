#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
30 60 90 120 150 180 210 240 270 + 00000...
*/
string minus30(const string& str){
  string input = str;
  int str_size = str.size();

  if(str_size < 2){
    return "0";
  }

  if(input[str.size() - 2] >= '3'){ // 십의 자리
    input[str.size() - 2] = (char)((int)input[str.size() - 2] - 3);
  }else{ // 윗 자리에서 -1
    int val = (s[str.size() - 2] - '0') + 10 - 3;
    s[str.size() - 2] = char(val + '0');

    int i = str.size() - 3;
    while(i >= 0){
      if(s[i] > '0'){
        s[i] = s[i] - 1;
        break;
      } else {
        s[i] = '9';
        i--;
      }
    }
  }

  int zero_count = 0;
  for(int i = 0 ; i < input.size(); i++){
    if(input[i] == '0') zero_count++;
  }
  input = input.substr(zero_count);

  return input;
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string input;
  cin >> input;
  sort(input.begin(), input.end());

  string start = "";
  string end = "1";
  for(int i = 0; i < input.size() -1 ; i++){
    start += '9';
    end += '0';
  }
  start += '0';

  while(start >= end){
    string temp = start; 
    sort(temp.begin(), temp.end());
    if( temp == input ){
      cout << start;
      return 0;
    }

    start = minus30(start);
  }

  cout << -1;

  return 0;
}