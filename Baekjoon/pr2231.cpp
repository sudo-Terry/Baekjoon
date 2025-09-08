#include<iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100100
using namespace std;

int n, min;

void solve() {
  cin >> n;

  int ans = 0;
  int input = n;
  int char_sum = 0; 
  string input_string = to_string(n);

  while(n){
    char_sum = 0;
    for(int i = 0; i < input_string.length(); i++){
      char_sum += (int) input_string[i] - '0';
    }

    if (char_sum + n == input){
      cout << char_sum;
      ans = n;
    }

    n--;
  }

  cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
  
  solve();

  return 0;
}
