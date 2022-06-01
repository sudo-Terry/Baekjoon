#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 55
using namespace std;

int tc, r, c; // col r row c
int arr[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1 ,0 };
int ans = 0;

void solve() {
  for(int i = 1; i <= r; i++){
    for(int j = 1; j<= c; j++){
      if (arr[i][j] > 0) {
        ans += 2;
      }
    }
  }
  for(int i = 1; i <= r; i++){
    for(int j = 1; j<= c; j++){
      for(int k = 0; k < 4; k++){
        if (arr[i][j] > arr[i + dy[k]][j + dx[k]]) {
          ans += arr[i][j] - arr[i + dy[k]][j + dx[k]];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input = "";
  
  cin >> tc;
  
  while (tc--) {
    ans = 0;
    memset(arr, 0, sizeof(arr));
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
      cin >> input;
      for(int j = 1; j<= c; j++){
        arr[i][j] = input.at(j-1) - '0';
        // cout << arr[i][j];
      }
      // cout << '\n';
    }
    
    solve();
    
    cout << ans << '\n';
  }
	return 0;
}