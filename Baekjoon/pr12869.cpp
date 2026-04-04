#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#define MAX 61

int N;
bool hp[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dx[6] = {9, 9, 3, 3, 1, 1};
int dy[6] = {3, 1, 9, 1, 9, 3};
int dz[6] = {1, 3, 1, 9, 3, 9};

void bfs(int x, int y, int z){
  visited[x][y][z] = true;
  queue<tuple<int, int, int>> q;
  q.push({x, y, z});

  int attack = 0;
  while(!q.empty()){
    int q_size = q.size();
    attack++;
    for(int i = 0; i <q_size; i++){
      auto [qx, qy, qz] = q.front();
      q.pop();

      for(int i = 0; i < 6; i++){
        int nx = qx - dx[i];
        int ny = qy - dy[i];
        int nz = qz - dz[i];

        if(nx < 0) nx = 0;
        if(ny < 0) ny = 0;
        if(nz < 0) nz = 0;

        if(!visited[nx][ny][nz]){
          if(nx == 0 && ny == 0 && nz == 0){
            cout << attack;
            return;
          }

          q.push({nx, ny, nz});
          visited[nx][ny][nz] = true;
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;
  int start_x = 0, start_y = 0, start_z = 0;
  if(N >= 1) cin >> start_x;
  if(N >= 2) cin >> start_y;
  if(N >= 3) cin >> start_z;

  bfs(start_x, start_y, start_z);

  return 0;
}