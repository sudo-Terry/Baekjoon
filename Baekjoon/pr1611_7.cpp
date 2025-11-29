#include <iostream>
using namespace std;

/*
13 
= 2 * 6 + 1 = 
2 * 2 * (3) + 1 
2 * 2 * (2 + 1) + 1
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T, N;

  cin >> T;
  while(T--){
    cin >> N;
    int ans = 0;
    while(N > 1){
      if(N % 2 == 1) ans++;

      N = N / 2 + N % 2;
    }

    cout << ans << '\n';
  }

  return 0;
}