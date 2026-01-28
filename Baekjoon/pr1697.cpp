#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100001

int N, K;
int visited[MAX];

int bfs(){
  queue<int> q;
  q.push(N);
  visited[N] = true;
  int ans = 0;

  while(!q.empty()){
    int q_size = q.size();
    ans++;

    for(int i = 0; i < q_size; i++){
      int curr = q.front();

      if(curr == K) return ans - 1;
      q.pop();

      if(curr * 2 < MAX && !visited[curr * 2]) {
        q.push(curr * 2);
        visited[curr * 2] = true;
      }
      if(curr + 1 < MAX && !visited[curr + 1]) {
        q.push(curr + 1);
        visited[curr + 1] = true;
      }
      if(curr - 1 >= 0 && !visited[curr - 1]) {
        q.push(curr - 1);
        visited[curr - 1] = true;
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> K;
  cout << bfs();

  return 0;
}