#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 10

bool visited[MAX];
vector<char> vec;
vector<int> ans;
int k;

bool validate_ans(){
  bool flag = true;

  for(int i = 0; i < k; i++){
    if(vec[i] == '<' && ans[i] > ans[i+1]) flag = false;
    if(vec[i] == '>' && ans[i] < ans[i+1]) flag = false;
  }

  return flag;
}

bool dfs_ub(){
  if(ans.size() == k + 1){
    if(validate_ans()){
      for(size_t i = 0; i < ans.size(); i++){
        cout << ans[i];
      }
      cout << '\n';
      return true;
    }
    return false;
  }

  for(int i = MAX - 1; i >= 0; i--){
    if(!visited[i]){
      visited[i] = true;
      ans.push_back(i);

      if(dfs_ub()) return true;

      ans.pop_back();
      visited[i] = false;
    }
  }

  return false;
}

bool dfs_lb(){
  if(ans.size() == k + 1){
    if(validate_ans()){
      for(size_t i = 0; i < ans.size(); i++){
        cout << ans[i];
      }
      cout << '\n';
      return true;
    }
    return false;
  }

  for(int i = 0; i < MAX; i++){
    if(!visited[i]){
      visited[i] = true;
      ans.push_back(i);

      if(dfs_lb()) return true;

      ans.pop_back();
      visited[i] = false;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> k;
  for(int i = 0; i < k; i++){
    char temp;
    cin >> temp;
    vec.push_back(temp);
  }

  dfs_ub();
  ans.clear();
  memset(visited, false, sizeof(visited));
  dfs_lb();

  return 0;
}