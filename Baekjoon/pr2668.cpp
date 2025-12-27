#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 110

vector<int> vec;
vector<vector<int>> adj;
vector<int> answer;
bool visited[MAX];
bool inStack[MAX];


void dfs(int current_node){
  inStack[current_node] = true;
  visited[current_node] = true;

  int next_node = adj[current_node][0];

  if(!visited[next_node]){
    dfs(next_node);
  }
  else if(inStack[next_node]){
    int temp = next_node;
    answer.push_back(temp);

    while(temp != current_node){
      temp = adj[temp][0];
      answer.push_back(temp);
    }
  }

  inStack[current_node] = false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;
  vec.resize(N + 1);
  adj.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> vec[i];
    adj[i].push_back(vec[i]);
  }

  for(int i = 1; i <= N; i++) {
    if(!visited[i]){
      dfs(i);
    }
  }

  sort(answer.begin(), answer.end());

  cout << answer.size() << '\n';
  for(int x : answer){
    cout << x << '\n';
  }

  return 0;
}