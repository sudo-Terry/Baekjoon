#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10

int N, M;
bool visited[MAX];
vector<int> vec, ans;

void dfs(){
  if(ans.size() == M){
    for(size_t i = 0; i < ans.size(); i++){
      cout << ans[i] << ' ';
    }
    cout <<'\n';
    
    return;
  }

  for(int i = 0; i < N; i++){
    if(!visited[i]){
      ans.push_back(vec[i]);
      visited[i] = true;
      dfs();

      ans.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());
  dfs();

  return 0;
}