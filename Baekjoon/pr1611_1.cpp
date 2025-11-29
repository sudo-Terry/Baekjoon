#include <iostream>
using namespace std;

/*
  E(X) * (N + counter) > sum + counter * 100
*/

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  long long N, target_score;
  long long score_sum = 0;
  long long ans = 0;

  cin >> N >> target_score;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    score_sum += temp;
  }

  int counter = 0;
  while(target_score * (N + counter) > (score_sum + counter * 100)){
    counter++;
  }

  cout << counter;

  return 0;
}