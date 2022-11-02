#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m, tc;
bool visited[MAX + 1] = {
    0,
};
int arr[MAX + 1] = {
    0,
};

void dfs(int nodenum, int count)
{
  if (count == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = nodenum; i <= n; i++)
    if (!visited[i])
    {
      visited[i] = true;
      arr[count] = i;
      dfs(i + 1, count + 1);
      visited[i] = false;
    }
}

void solve()
{
  dfs(1, 0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n >> m;

  solve();

  return 0;
}
