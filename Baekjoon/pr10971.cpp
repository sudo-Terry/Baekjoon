#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX 11

int N;
int W[MAX][MAX];
bool visited[MAX];
vector<int> vec;
int ans = INT_MAX;

void backtrack(){
  if(vec.size() == N){
    // for(size_t i = 0; i < vec.size(); i++){
    //   cout << vec[i] << ' ';
    // }
    // cout <<'\n';

    int cost = 0;

    for(size_t i = 0; i < vec.size() - 1; i++){
      int curr = vec[i];
      int next = vec[i + 1];

      if(W[curr][next] == 0) return; // 불가능한 경로

      cost += W[curr][next];
    }
    if(W[vec[N - 1]][vec[0]] == 0) return; // 불가능한 경로
    cost += W[vec[N - 1]][vec[0]];

    ans = min(ans, cost);
  }

  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      visited[i] = true;
      vec.push_back(i);

      backtrack();

      vec.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> W[i][j];
    }
  }
  backtrack();

  cout << ans;

  return 0;
}