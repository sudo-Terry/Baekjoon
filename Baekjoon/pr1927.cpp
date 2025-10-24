#include <iostream>
#include <queue>
using namespace std;

int N, event;
priority_queue<int> pq;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N;

  while(N--){
    cin >> event;
    if(event == 0){
      if(pq.empty()) cout << '0' << '\n';
      else {
        cout << pq.top() * -1 << '\n';
        pq.pop();
      }
    }else {
      pq.push(event * -1);
    }
    
  }

  return 0;
}