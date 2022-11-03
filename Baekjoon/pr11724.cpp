#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1010
using namespace std;

int n, m;
int count_connected_component = 0;
vector<int> adj[MAX];
bool visited[MAX] = {
    0,
};

void dfs(int nodenum)
{
  if (visited[nodenum])
    return;
  visited[nodenum] = true;
  for (int i = 0; i < adj[nodenum].size(); i++)
    dfs(adj[nodenum][i]);
}

void solve()
{
  for (int i = 1; i <= n; i++)
  {
    if (visited[i])
      continue;
    dfs(i);
    count_connected_component++;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  solve();

  cout << count_connected_component;

  return 0;
}
