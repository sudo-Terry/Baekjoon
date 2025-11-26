#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> towers(N+1);
  for(int i = 0; i < N; i++){
    cin >> towers[i];
  }

  /*
    스택 top의 높이가 h보다 작으면 오른쪽의 어떤 탑의 레이저도 못 막음
    스택 top의 높이가 h보다 크면 정답
    현재 탑을 스택에 push
    
  */
  stack<pair<int, int>> tower_stack;
  tower_stack.push({0, towers[0]});
  cout << '0' << ' '; 
  for(int i = 1; i < N; i++){
    int tower_top = tower_stack.top().second;

    while(!tower_stack.empty() && tower_stack.top().second < towers[i]){
      tower_stack.pop();
    }

    if(tower_stack.empty()) cout << '0' << ' '; 
    else cout << tower_stack.top().first + 1 << ' ';

    tower_stack.push({i , towers[i]});
  }

  return 0;
}