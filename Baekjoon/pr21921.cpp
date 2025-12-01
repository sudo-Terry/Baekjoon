#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, X;
  vector<int> visitors;
  int max_val = 0;
  int counter = 1;
  cin >> N >> X;
  for(int i = 0; i < N; i++){
    int visitor;
    cin >> visitor;
    visitors.push_back(visitor);
  }

  int sum = 0;
  for(int i = 0; i < X; i++){
    sum += visitors[i];
  }
  max_val = sum;
  for(int i = 1; i < N - X; i++){
    int start = i;
    int end = i + X;

    sum -= visitors[start - 1];
    sum += visitors[end];

    if(sum == max_val) counter++;
    else if (sum > max_val){
      max_val = sum;
      counter = 1;
    }
  }

  if (max_val == 0) cout << "SAD";
  else cout << max_val << '\n' << counter;

  return 0;
}