#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> plus;
  priority_queue<int, vector<int>, greater<int>> minus;

  int x;
  for(int i = 0; i < N; i++){
    cin >> x;

    if(x == 0){
      if(plus.empty() && minus.empty()){
        cout << "0" << '\n';
      }
      else if(plus.empty()){
        cout << -minus.top() << '\n';
        minus.pop();
      }
      else if(minus.empty()){
        cout << plus.top() << '\n';
        plus.pop();
      }else{
        if(plus.top() < minus.top()){
          cout << plus.top() << '\n';
          plus.pop();
        }else{
          cout << -1 * minus.top() << '\n';
          minus.pop();
        }
      }
    }else{
      if(x > 0) plus.push(x);
      else minus.push(x * (-1));
    }
  }

  return 0;
}