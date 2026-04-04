#include <iostream>
#include <queue>
using namespace std;

/*
2개를 넣었을때 (홀 -> 홀)

중간값보다 작은거 2 -> 중간값이 왼쪽으로 1칸 이동
중간값보다 큰거 2 -> 중간값이 오른쪽으로 1칸 이동
중간값보다 큰거, 작은거 11 -> 중간값 유지
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  priority_queue<int> left_tree;
  priority_queue<int, vector<int>, greater<int>> right_tree;

  int N, x;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x;

    if(left_tree.empty() || x <= left_tree.top()){ // 분기
      left_tree.push(x);
    } else {
      right_tree.push(x);
    }

    if(left_tree.size() > right_tree.size() + 1){ // 트리 크기
      right_tree.push(left_tree.top());
      left_tree.pop();
    }
    else if(right_tree.size() > left_tree.size()){
      left_tree.push(right_tree.top());
      right_tree.pop();
    }

    cout << left_tree.top() << '\n';
  }
  return 0;
}