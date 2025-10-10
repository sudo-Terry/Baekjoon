#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 110

int N;
int ans = 0;
bool visited[26];

bool solve(string str) {
  char before = 0;
  for(int i = 0; i < str.length(); i++){
    if(str[i] != before){
      if(visited[str[i] - 'a']) return false;
      visited[str[i] - 'a'] = true;
    }
    before = str[i];
  }
  return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
  
  while(N--){
    memset(visited, false, sizeof(visited));

    string str;
    cin >> str;
    if (solve(str)) ans++;
  }

  cout << ans;

  return 0;
}
