#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<long long, long long>> q;
long long a, b;
int ans = -1;

int bfs(long long a, long long b)
{
  q.push(make_pair(a, 1));
  while (!q.empty())
  {
    pair<long long, long long> current_value = q.front();
    q.pop();
    if (current_value.first == b)
    {
      return current_value.second;
    }
    if (current_value.first * 2 <= b)
    {
      q.push(make_pair(current_value.first * 2, current_value.second + 1));
    }
    if (current_value.first * 10 + 1 <= b)
    {
      q.push(make_pair((current_value.first * 10) + 1, current_value.second + 1));
    }
  }
  return -1;
}
void solve()
{
  cout << bfs(a, b);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> a >> b;

  solve();

  return 0;
}
