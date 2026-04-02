#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX 102

vector<pair<int,int>> pos;
bool visited[MAX];

int dist(pair<int,int> a, pair<int,int> b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void bfs(int n){
  queue<int> q;
  q.push(0);
  visited[0] = true;

  while(!q.empty()){
    int cur = q.front(); 
    q.pop();

    if(cur == n + 1){
      cout << "happy" << '\n';
      return;
    }

    for(int i = 0; i < n + 2; i++){
      if(!visited[i] && dist(pos[cur], pos[i]) <= 1000){
        visited[i] = true;
        q.push(i);
      }
    }
  }

  cout << "sad" << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; 
  cin >> t;
  while(t--){
    int n; 
    cin >> n;
    pos.clear();
    fill(visited, visited + MAX, false);

    int x, y;
    cin >> x >> y;
    pos.push_back({x, y});
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      pos.push_back({x, y});
    }

    cin >> x >> y;
    pos.push_back({x, y});

    bfs(n);
  }
}