#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, score, P;
vector<int> scores;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> score >> P;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    scores.push_back(temp);
  }

  if (N == 0) {
    cout << 1;
    return 0;
  }

  // 랭킹이 꽉 찼고, 새 점수가 들어갈 자리가 없을 경우
  if (N == P && scores.back() == score) {
    cout << -1;
    return 0;
  }

  scores.push_back(score);
  sort(scores.begin(), scores.end(), greater<int>());
  
  int rank;
  for(int i = 0; i < scores.size() ; i++){
    if(scores[i] == score){
      rank = i + 1;
      break;
    }
  }

  if (scores.size() > P) scores.pop_back();

  cout << rank;

  return 0;
}