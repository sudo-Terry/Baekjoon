#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  long long N;
  cin >> N;

  if(N * N <= 100000000) cout << "Accepted";
  else cout << "Time limit exceeded";

  return 0;
}