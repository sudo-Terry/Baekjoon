#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 26

int N, K;
vector<string> vec;
bool visited[MAX];
int max_ans = 0;

// a n t i c

void backtrack(int idx, int count){
  if(count == K){
    int ans = 0;
    for(size_t i = 0; i < vec.size(); i++){
      bool flag = true;
      for(size_t j = 0; j < vec[i].size(); j++){
        if(!visited[vec[i][j] - 'a']) flag = false;
      }

      if(flag) ans++;
    }

    max_ans = max(max_ans, ans);

    return;
  }

  for(int i = idx; i < 26; i++){
    if(!visited[i]){
      visited[i] = true;
      backtrack(i + 1, count + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> K;
  for(int i = 0; i < N; i++){
    string temp;
    cin >> temp;
    vec.push_back(temp);
  }

  if( K < 5){
    cout << '0';
  }else{
    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    backtrack(0, 5);

    cout << max_ans;
  }

  return 0;
}