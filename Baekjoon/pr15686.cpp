#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 50
#define INF 987654321
#define EMPTY 0
#define HOUSE 1
#define CHICKEN 2

int N, M;
vector<int> chicken_dist;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<pair<int, int>> selected;
int matrix[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dist;
int ans = INF;

void calculate_dist() {
  int city_dist = 0;

  for (auto& h : houses) {
    int min_h_dist = INF;
    for (auto& s : selected) {
      int d = abs(h.first - s.first) + abs(h.second - s.second);
      min_h_dist = min(min_h_dist, d);
    }
    city_dist += min_h_dist;
  }

  ans = min(ans, city_dist);
}

void select_chicken(int idx, int count) {
  if (count == M) {
    calculate_dist();
    return;
  }

  for (int i = idx; i < chickens.size(); i++) {
    selected.push_back(chickens[i]);
    select_chicken(i + 1, count + 1);
    selected.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> matrix[i][j];

      if(matrix[i][j] == CHICKEN) chickens.push_back({i, j});
      if(matrix[i][j] == HOUSE) houses.push_back({i, j});
    }
  }

  select_chicken(0, 0);
  cout << ans;

  return 0;
}