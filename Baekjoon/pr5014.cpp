#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int F, S, G, U, D;
int dx[2] = {0,};
int buttonClicks = 0;

class Graph{
  public:
  int nodeCount;
  vector<bool> visited;

  Graph(int nodeCount): nodeCount(nodeCount) {
    visited.resize(nodeCount);
  }

  void bfs(int startNode){
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()){
      int size = q.size();

      for(int i = 0; i < size; i++){
        int currentNode = q.front();
        q.pop();

        if(currentNode == G){
          cout << buttonClicks;
          return;
        }

        for(int i = 0; i < 2; i++){
          int nextNode = currentNode + dx[i];
          if(nextNode > 0 && nextNode <= F && !visited[nextNode]){
            visited[nextNode] = true;
            q.push(nextNode);
          }
        }
      }
      buttonClicks++;
    }
    cout << "use the stairs";
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> F >> S >> G >> U >> D;
  dx[0] = U;
  dx[1] = -D;

  Graph g(F + 1);
  g.bfs(S);

  return 0;
}