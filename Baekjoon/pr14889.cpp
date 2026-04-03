#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define MAX 21

int N;
int S[MAX][MAX];
bool selected[MAX];
int min_diff = INT_MAX;

void backtrack(int idx, int select_count){
  if(select_count > N / 2) return;
  if(((N / 2) - select_count) > N - idx) return;

  if(idx == N){
    if (select_count == N / 2){
      int team1 = 0;
      int team2 = 0;

      for(int i = 0; i < N; i++){
        if(selected[i]){
          for(int j = i + 1; j < N; j++){
            if(selected[j] && i != j) team1 += S[i][j] + S[j][i];
          }
        }else{
          for(int j = i + 1; j < N; j++){
            if(!selected[j] && i != j) team2 += S[i][j] + S[j][i];
          }
        }
      }

      min_diff = min(min_diff, abs(team1 - team2));
    }
    return;
  }

  selected[idx] = true;
  backtrack(idx + 1, select_count + 1);

  selected[idx] = false;
  backtrack(idx + 1, select_count);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> S[i][j];
    }
  }

  // 대칭성 pruning
  selected[0] = true; 
  backtrack(1, 1);

  cout << min_diff;

  return 0;
}