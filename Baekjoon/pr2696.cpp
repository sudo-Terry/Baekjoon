#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 10010
using namespace std;

int T, M;
int median;
int num;

// 최대힙 - median - 최소힙

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  
  while(T--){
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>, less<int>> max_pq;
    vector<int> medians;
    cin >> M;

    cout << floor((M + 1) / 2) << '\n';

    cin >> median;
    medians.push_back(median);
    
    for(int i = 1; i < M; i++){
      cin >> num;

      if(i % 2 == 0){ // 2n+1
        if(!min_pq.empty() && min_pq.top() <= num){
          median = min_pq.top();
          min_pq.pop();
          min_pq.push(num);
        }else if(!max_pq.empty() && max_pq.top() > num){
          median = max_pq.top();
          max_pq.pop();
          max_pq.push(num);
        }else {
          median = num;
        }
        medians.push_back(median);
      }else { // 2n
        if(num > median){ 
          min_pq.push(num);
          max_pq.push(median);
        }else{
          max_pq.push(num);
          min_pq.push(median);
        }
      }
    }
    for(int i = 0; i < medians.size(); i++){
      cout << medians[i] << ' ';
      if((i + 1) % 10 == 0 && i != medians.size() - 1){
        cout << '\n';
      }
    }
    cout << '\n';
  }

  return 0;
}