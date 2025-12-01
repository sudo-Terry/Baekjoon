#include <iostream>
#include <cstring>
using namespace std;

// a 등장 횟수 사이즈로 슬라이딩 윈도우를 해보면서.. 그 안에 a가 가장 많은거 선택
// a등장 횟수 - a 가 가장 많은거에서 a 횟수

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string input;
  cin >> input;

  int a_count = 0;
  int b_count = 0;
  for(size_t i = 0; i < input.size(); i++){
    if(input[i] == 'a') a_count++;
    else b_count++;
  }


  // 링 연결
  input += input.substr(0, a_count);
  int window_a_count = 0;
  int max_a_count = 0;
  for(int i = 0; i < a_count; i++){
    if(input[i] == 'a') window_a_count++;
  }
  max_a_count = window_a_count;
  for(size_t start = 1; start <= input.size(); start++){
    if(input[start - 1] == 'a') window_a_count--;
    if(input[start + a_count - 1] == 'a') window_a_count++;

    max_a_count = max(max_a_count, window_a_count);
  }

  cout << a_count - max_a_count;

  return 0;
}