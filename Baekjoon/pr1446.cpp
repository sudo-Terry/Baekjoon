#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define MAX 10000

int N, D;
vector<pair<int, int>> adj[MAX + 1];
int dist[MAX + 1];
bool visited[MAX + 1];

void dijkstra(int start){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while(!pq.empty()){
    int curr_dist = pq.top().first;
    int curr_pos = pq.top().second;
    pq.pop();

    if(visited[curr_pos]) continue;
    visited[curr_pos] = true;

    for(int i = 0; i < adj[curr_pos].size(); i++){
      int next_dist = adj[curr_pos][i].first;
      int next_pos = adj[curr_pos][i].second;

      if(dist[next_pos] > curr_dist + next_dist){
        dist[next_pos] = curr_dist + next_dist;
        pq.push({dist[next_pos], next_pos});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> D;
  for(int i = 0; i <= D; i++){
    adj[i].push_back({1, i+1});
  }
  int start, end, len;
  for(int i = 0; i < N; i++){
    cin >> start >> end >> len;
    adj[start].push_back({len, end});
  }
  for(int i = 0; i <= D; i++){
    dist[i] = INT_MAX;
  }
  dijkstra(0);

  cout << dist[D];

  return 0;
}