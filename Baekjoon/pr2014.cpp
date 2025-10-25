#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 110
const long long LIMIT = 1LL << 31; 
using namespace std;

int N, K;
int num[MAX] = {0,};
long long prev_num = -1;
priority_queue<int, vector<int>, greater<long long>> pq; // 최소 Pq

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> K >> N;
  for(int i = 0; i < K; i++){
    cin >> num[i];
    pq.push(num[i]);
  }
  

  // 최소 우선순위 큐로 최댓값인 2e31 넘어가지 않는 수만 빼서 소수 다 곱해서 넣어주기
  for(int i = 0; i < N; i++){
    while(prev_num == pq.top()){
      pq.pop();
    }
    long long top = pq.top();
      
    for(int j = 0; j < K; j++){
      if (top * num[j] >= LIMIT) break;
      pq.push(top * num[j]);
    }

    prev_num = top;
    pq.pop();
  }

  cout << prev_num;

  return 0;
}