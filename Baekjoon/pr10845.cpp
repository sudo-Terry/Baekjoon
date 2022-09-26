#include<iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, tc;
queue<int> q;
string command;

void solve() {
  cin >> command;
  if(command == "push"){
    cin >> n;
    q.push(n);
  }else if(command == "front"){
    if(q.empty()){
      cout << "-1" << '\n';
    }else{
      cout << q.front() << '\n';
    }
  }else if(command == "back"){
    if(q.empty()){
      cout << "-1" << '\n';
    }else{
      cout << q.back() << '\n';
    }
  }else if(command == "pop"){
    if(q.empty()){
      cout << "-1" << '\n';
    }else{
      cout << q.front() << '\n';
      q.pop();
    }
  }else if(command == "size"){
      cout << q.size() << '\n';
  }else if(command == "empty"){
    if(q.empty()){
      cout << '1' << '\n';
    }else{
      cout << '0' << '\n';
    }
  }
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> tc;
  
  while(tc--){
    solve();
  }

  return 0;
}
