#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1010
#define MASK 1000000LL

int N, K;
long long score[MAX];
long long target_score;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N; i++){
    int country, gold, silver, bronze;
    cin >> country >> gold >> silver >> bronze;

    score[country - 1] = (long long)gold * MASK * MASK + silver * MASK + bronze;
    if(country == K) target_score = score[country - 1];
  }

  sort(score, score + N, greater<long long>());
  for(int i = 0; i < N; i++){
    if(score[i] == target_score) {
      cout << i + 1;
      break;
    }
  }

  return 0;
}