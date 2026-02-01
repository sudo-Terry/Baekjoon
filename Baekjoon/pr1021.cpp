#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
*/

deque<int> dq;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  int total_count = 0;

  for(int i = 1; i <= N; i++) dq.push_back(i);
  for(int i = 0; i < M; i++){
    int target;
    cin >> target;

    int idx = 0;
    for (int i = 0; i < dq.size(); i++) {
      if (dq[i] == target) {
        idx = i;
        break;
      }
    }

    // 왼쪽
    if (idx <= dq.size() / 2) {
      for (int i = 0; i < idx; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
        total_count++;
      }
    } else {// 오른쪽
      int reverse_idx = dq.size() - idx;
      for (int i = 0; i < reverse_idx; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
        total_count++;
      }
    }

    dq.pop_front();
  }

  cout << total_count << '\n';

  return 0;
}