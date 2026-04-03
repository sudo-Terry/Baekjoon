#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10010

int N, M;
bool visited[MAX];
vector<int> vec;
vector<int> vec_selected;

void backtrack(int select_count){
  if(select_count == M){
    for(int i = 0; i < M; i++){
      cout << vec_selected[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int prev = -1;
  for(int i = 0; i < N; i++){
    if(visited[i]) continue;
    
    visited[i] = true;
    vec_selected.push_back(vec[i]);
    
    backtrack(select_count + 1);
    
    vec_selected.pop_back();
    visited[i] = false;

    prev = vec[i];
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  int temp;
  for(int i = 0; i < N; i++){
    cin >> temp;
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());

  backtrack(0);

  return 0;
}