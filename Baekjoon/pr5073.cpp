#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int a, b, c;
  while (true){
    cin >> a >> b >> c;
    if(a == 0) return 0;

    int max_val = max(a, max(b, c));
    if(max_val < a + b + c - max_val){
      if(a == b && b == c) cout << "Equilateral" << '\n';
      else if(a == b || b == c || a == c) cout << "Isosceles" << '\n';
      else cout << "Scalene" << '\n';
    }else{
      cout << "Invalid" << '\n';
    }
  }
}