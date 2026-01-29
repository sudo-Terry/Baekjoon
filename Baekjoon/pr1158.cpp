#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  queue<int> q;
  queue<int> ans;

  for(int i = 1; i <= N; i++) q.push(i);

  int counter = 0;
  while(!q.empty()){
    counter++;
    if(counter % K == 0){
      ans.push(q.front());
    }else{
      q.push(q.front());
    }
    q.pop();
  }

  cout << "<";
  for(int i = 0; i < N; i++){
    cout << ans.front();
    ans.pop();
    if(!ans.empty()) cout << ", ";
  }
  cout << ">";

  return 0;
}