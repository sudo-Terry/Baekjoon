#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N*N; i++){
    int temp;
    cin >> temp;
    pq.push(-1 * temp);
    if(pq.size() > N) pq.pop();
  }

  cout << -1 * pq.top();

  return 0;
}