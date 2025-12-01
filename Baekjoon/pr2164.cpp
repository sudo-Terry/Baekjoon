#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  queue<int> q;
  cin >> N;
  for(int i = 1; i <= N; i++ ){
    q.push(i);
  }

  while(q.size() > 1){
    int drop = q.front();
    q.pop();

    int no_drop = q.front();
    q.pop();
    q.push(no_drop);
  }

  int last = q.front();
  cout << last;

  return 0;
}