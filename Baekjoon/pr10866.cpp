#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  deque<int> dq;
  while(N--){
    string cmd;
    cin >> cmd;

    if(cmd == "push_front"){
      int target;
      cin >> target;
      dq.push_front(target);
    }else if(cmd == "push_back"){
      int target;
      cin >> target;
      dq.push_back(target);
    }else if(cmd == "pop_front"){
      if(dq.empty()) cout << "-1" << '\n';
      else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    }else if(cmd == "pop_back"){
      if(dq.empty()) cout << "-1" << '\n';
      else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    }else if(cmd == "size"){
      cout << dq.size() << '\n';
    }else if(cmd == "empty"){
      cout << (dq.empty() ? '1' : '0') << '\n';
    }else if(cmd == "front"){
      if(dq.empty()) cout << "-1" << '\n';
      else cout << dq.front() << '\n';
    }else if(cmd == "back"){
      if(dq.empty()) cout << "-1" << '\n';
      else cout << dq.back() << '\n';
    }
  }

  return 0;
}