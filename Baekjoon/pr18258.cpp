#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

/*
  push X: 정수 X를 큐에 넣는 연산이다.
  pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
  size: 큐에 들어있는 정수의 개수를 출력한다.
  empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
  front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
  back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  queue<int> q;
  cin >> N;
  while(N--){
    string func;
    cin >> func;

    if(func == "push"){
      int temp;
      cin >> temp;
      q.push(temp);
    }else if(func == "pop"){
      if(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << '\n';
      }else{
        cout << "-1" << '\n';
      }
    }else if(func == "size"){
      cout << q.size() << '\n';
    }else if(func == "empty"){
      if(!q.empty()){
        cout << "0" << '\n';
      }else{
        cout << "1" << '\n';
      }
    }else if(func == "front"){
      if(!q.empty()){
        int front = q.front();
        cout << front << '\n';
      }else{
        cout << "-1" << '\n';
      }
    }else if(func == "back"){
      if(!q.empty()){
        int back = q.back();
        cout << back << '\n';
      }else{
        cout << "-1" << '\n';
      }
    }
  }

  return 0;
}