#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
1
6  2 ~ 7    1 + 1 ~ 6
12 8 ~ 19   1 + 6 * 1 + 1 ~ 12
18 20 ~ 37  1 + 6 * 3 + 1 ~ 18
24 38 ~ 61  1 + 6 * 6 + 1 ~ 24 -> 1 + 6(1 + 2 + .. n-1) + 1 ~ 6 * n -> 답n+1
...
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;

  // 1 + 3n(n-1) + 1 ~ 1 + 3n(n-1) + 6n
  int n = 1;
  while(true){
    if ( 1 + 3*n*(n-1) >= N) {
      cout << n;
      return 0;
    }

    n++;
  }

  return 0;
}