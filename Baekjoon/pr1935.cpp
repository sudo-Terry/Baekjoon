#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX 30

int N;
int num[MAX];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  stack<double> stk;
  string str;
  cin >> N;
  cin >> str;
  for(int i = 0; i < N; i ++){
    cin >> num[i];
  }
  for(int i = 0; i < str.length(); i++){
    char c = str[i];
    if ( 'A' <= c && c <= 'Z' ){
      stk.push(num[c - 'A']);
    }else {
      double x, y;
      x = stk.top(); stk.pop();
      y = stk.top(); stk.pop();
      
      if(c == '*') stk.push(y * x);
      else if(c == '+') stk.push(y + x);
      else if(c == '-') stk.push(y - x);
      else if(c == '/') stk.push(y / x);
    }
  }

  cout << fixed << setprecision(2) << floor(stk.top() * 100) / 100.0;
}