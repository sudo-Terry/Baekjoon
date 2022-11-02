#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10010
using namespace std;

int n, m;
int ans = 0;
queue<pair<int, int>> q;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0}; // middle up right down left
bool visited[MAX][MAX] = {
    0,
};
int arr[MAX][MAX] = {
    0,
};
int delta[MAX][MAX] = {
    0,
};

bool is_seperated()
{
  int temp_x, temp_y;
  memset(visited, false, sizeof(visited));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] > 0)
      {
        temp_y = i;
        temp_x = j;
        break;
      }
    }
  }

  q.push(make_pair(temp_y, temp_x));
  visited[temp_y][temp_x] = true;
  while (!q.empty())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (arr[ny][nx] > 0 && !visited[ny][nx] && ny < n && nx < m && nx >= 0 && ny >= 0)
      {
        q.push(make_pair(ny, nx));
        visited[ny][nx] = true;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && arr[i][j] > 0)
        return true;
    }
  }
  return false;
}

void bfs()
{
  q.push(make_pair(1, 1));
  visited[1][1] = true;
  while (!q.empty())
  {
    int count_water = 0;
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (arr[ny][nx] <= 0)
      {
        count_water++;
      }
      if (!visited[ny][nx] && ny < n && nx < m && nx >= 0 && ny >= 0)
      {
        q.push(make_pair(ny, nx));
        visited[ny][nx] = true;
      }
    }
    delta[y][x] = count_water;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      arr[i][j] -= delta[i][j];
    }
  }
}

void solve()
{
  while (true)
  {
    bfs();
    ans++;
    if (is_seperated())
    {
      break;
    }
    memset(visited, false, sizeof(visited));
  }
  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  solve();

  return 0;
}
