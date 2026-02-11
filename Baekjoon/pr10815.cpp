#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N;
  vector<int> cards(N);
  for(int i = 0; i < N; i++){
    cin >> cards[i];
  }
  cin >> M;
  vector<int> target(M);
  for(int i = 0; i < M; i++){
    cin >> target[i];
  }
  sort(cards.begin(), cards.end());

  for(int i = 0; i < M; i++){
    int start = 0;
    int end = cards.size() - 1;
    bool flag = false;

    while (start <= end){
      int mid = (start + end) / 2;

      if(cards[mid] > target[i]){
        end = mid - 1;
      }else if(cards[mid] < target[i]){
        start = mid + 1;
      }else if(cards[mid] == target[i]){
        flag = true;
        break;
      }
    }
    cout << (flag ? "1 " : "0 ");
  }

  return 0;
}