#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000100

int tc, N;
int stock[MAX];
bool visited[MAX];

long long solve(){
  long long sum = 0;
  memset(visited, false, sizeof(visited));
  
  int max_val = -1;
  for(int i = N-1; i >= 0; i--){
    if(stock[i] > max_val){
      max_val = stock[i];
    } else {
      sum += (long long)(max_val - stock[i]);
    }
  }

  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> tc;

  while(tc--){
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> stock[i];
    }

    cout << solve() << '\n';
  }

  return 0;
}